
#include "socket.h"
#include <QDebug>

Socket::Socket()
{
    /*
    db = QSqlDatabase::addDatabase("QMYSQL", "mathle");
    db.setHostName("pixio-playground");
    db.setPort(3306);
    //db.setDatabaseName("mathle");
    db.setUserName("root");
    db.setPassword("passwordlol");
    if(!db.open())
    {
        qDebug() << "Didn't Connect!";
    }

    QSqlQuery query("SELECT count(1) from mathle.users WHERE users.username = 'test' AND users.password = 'test'");

    if(query.record().count() == 1)
    {
        qDebug() << "Successful Login";
    }
    else
    {
        qDebug() << "Unsuccessful login";
    }
    */

    std::vector<std::string> tables;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL *connection, mysql;

    int state;

    mysql_init(&mysql);

    connection = mysql_real_connect(&mysql,"localhost","client","client","mathle",3306,0,0);

    if (connection == NULL)
    {
        qDebug() << mysql_error(&mysql);
    }

    state = mysql_query(connection, "SELECT count(1) from mathle.users WHERE users.username = 'test1' AND users.password = 'test'");

    if(state != 0)
    {
        qDebug() << mysql_error(connection);
    }

    result = mysql_store_result(connection);

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

}

void Socket::connect()
{

}

void Socket::disconnect()
{

}
