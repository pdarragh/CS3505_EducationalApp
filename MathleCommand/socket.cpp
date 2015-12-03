#include "socket.h"
#include <QDebug>

Socket::Socket()
{
    /*
    std::vector<std::string> tables;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL *connection, mysql;

    int state;
    */

    mysql_init(&mysql);

    /*
    connection = mysql_real_connect(&mysql,"localhost","client","client","mathle",3306,0,0);

    if (connection == NULL)
    {
        qDebug() << mysql_error(&mysql);
    }

    state = mysql_query(connection, "SELECT count(1) from mathle.users WHERE users.username = 'test' AND users.password = 'test'");

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }

    result = mysql_store_result(connection);
    */

    /*
    while ( ( row = mysql_fetch_row(result)) != NULL )
    {
        //tables.push_back(row[0]);
        qDebug() << row[0];
        qDebug() << row[1];
        qDebug() << row[2];
    }
    */

    //qDebug() << mysql_num_rows(result);

    /*
    row = mysql_fetch_row(result);

    if(row != NULL)
    {
        int num_results = atoi(row[0]);
        if(num_results == 1)
        {
            qDebug() << "User Exists!";
        }
        else if(num_results == 0)
        {
            qDebug() << "User Doesn't Exist";
        }
        else
        {
            qDebug() << "Error!";
        }
    }
    else
    {
        qDebug() << "Error!";
    }

    mysql_free_result(result);
    mysql_close(connection);
    */

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

bool Socket::verifyUserLogin(QString username, QString password)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    int state;

    QString query("SELECT count(1) from mathle.users WHERE users.username = '");
    query.append(username);
    query.append("' AND users.password = '");
    query.append(password);
    query.append("'");

    qDebug() << query;

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
    }
    else
    {
        qDebug() << "Error!";
    }

    mysql_free_result(result);

    return valid;
}
