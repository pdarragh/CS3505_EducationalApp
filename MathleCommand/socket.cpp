#include "socket.h"
#include <QDebug>

Socket::Socket()
{
    mysql_init(&mysql);
}

Socket::~Socket()
{

}

void Socket::connect()
{
    connection = mysql_real_connect(&mysql,"localhost","client","client","mathle",3306,0,0);

    if (connection == NULL)
    {
        qDebug() << mysql_error(&mysql);
    }
}

void Socket::disconnect()
{
    mysql_close(connection);
}

int Socket::verifyUserLogin(QString username, QString password)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    int state;

    QString query("SELECT count(1), users.student from mathle.users WHERE users.username = '");
    query.append(username);
    query.append("' AND users.password = '");
    query.append(password);
    query.append("'");

    std::string queryString = query.toStdString();
    const char* charArray = queryString.c_str();

    state = mysql_query(connection, charArray);

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }

    result = mysql_store_result(connection);

    row = mysql_fetch_row(result);

    bool valid = false;
    bool isStudent = true;

    if(row != NULL)
    {
        int num_results = atoi(row[0]);
        if(num_results == 1)
        {
            qDebug() << "User Exists!";
            valid = true;
        }
        else if(num_results == 0)
        {
            qDebug() << "User Doesn't Exist";
        }
        else
        {
            qDebug() << "Error!";
        }

        int student = atoi(row[1]);
        if(student == 0)
        {
            student = false;
        }
    }
    else
    {
        qDebug() << "Error!";
    }

    mysql_free_result(result);

    if(!valid)
    {
        return AccountType::Invalid;
    }
    else if(!isStudent)
    {
        return AccountType::Teacher;
    }
    else
    {
        return AccountType::Student;
    }

    return valid;
}


bool Socket::createUser(QString username, QString password, bool isStudent)
{
    int student;
    if(isStudent)
    {
        student = 1;
    }
    else
    {
        student = 0;
    }

    // now insert into database
    QString insertQuery("INSERT INTO mathle.users (username, password, student) VALUES(");
    insertQuery.append(username);
    insertQuery.append(",");
    insertQuery.append(password);
    insertQuery.append(",");
    insertQuery.append(student);
    insertQuery.append(")");

    std::string insertString = insertQuery.toStdString();
    const char* insertCharArray = insertString.c_str();

    int state = mysql_query(connection, insertCharArray);

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
        return false;
    }

    return true;
}




StudentResults Socket::getStudentResults(QString username)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    int state;

    QString query("SELECT results.level, results.score, results.wrong_answers from mathle.users, mathle.results WHERE users.username = '");
    query.append(username);
    query.append("' AND users.id = results.user_id");

    std::string queryString = query.toStdString();
    const char* charArray = queryString.c_str();

    state = mysql_query(connection, charArray);

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }

    result = mysql_store_result(connection);

    //set up variables for looking through result
    int levelPos = 0;
    int scorePos = 1;
    int wrongPos = 2;
    StudentResults results;
    results.setUserName(username);

    while( (row = mysql_fetch_row(result)) != NULL)
    {
        int level = atoi(row[levelPos]);
        int score = atoi(row[scorePos]);
        int wrong = atoi(row[wrongPos]);

        results.setLevelComplete(level, true);
        results.setLevelScore(level, score);
        results.setLevelMisses(level, wrong);
    }

    mysql_free_result(result);

    return results;
}

std::vector<StudentResults> Socket::getAllStudentResults()
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    int state;

    QString query("SELECT users.username, results.level, results.score, results.wrong_answers from mathle.users, mathle.results WHERE users.id = results.user_id AND users.student = 1 ORDER BY users.username ASC");

    std::string queryString = query.toStdString();
    const char* charArray = queryString.c_str();

    state = mysql_query(connection, charArray);

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }

    result = mysql_store_result(connection);

    //set up variables for looking through result
    std::vector<StudentResults> resultVector;
    int namePos = 0;
    int levelPos = 1;
    int scorePos = 2;
    int wrongPos = 3;
    StudentResults results;

    while( (row = mysql_fetch_row(result)) != NULL)
    {
        QString name = row[namePos];

        if(name != results.getUserName())
        {
            resultVector.push_back(results);
            results = StudentResults();
        }

        int level = atoi(row[levelPos]);
        int score = atoi(row[scorePos]);
        int wrong = atoi(row[wrongPos]);

        results.setUserName(name);
        results.setLevelComplete(level, true);
        results.setLevelScore(level, score);
        results.setLevelMisses(level, wrong);
    }

    mysql_free_result(result);

    return resultVector;
}


void Socket::recordStudentResult(QString username, int level, int score, int misses)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    int state;

    // first let's get the user id
    QString query("SELECT users.user_id from mathle.users WHERE users.username = '");
    query.append(username);
    query.append("'");

    std::string queryString = query.toStdString();
    const char* charArray = queryString.c_str();

    state = mysql_query(connection, charArray);

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }

    result = mysql_store_result(connection);

    row = mysql_fetch_row(result);

    if(row == NULL)
    {
        throw;
    }

    int userID = atoi(row[0]);

    mysql_free_result(result);


    // now insert into database
    QString insertQuery("INSERT INTO mathle.results (user_id, level, score, wrong_answers) VALUES(");
    insertQuery.append(userID);
    insertQuery.append(",");
    insertQuery.append(level);
    insertQuery.append(",");
    insertQuery.append(score);
    insertQuery.append(",");
    insertQuery.append(misses);
    insertQuery.append(")");

    std::string insertString = query.toStdString();
    const char* insertCharArray = insertString.c_str();

    state = mysql_query(connection, insertCharArray);

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }
}

