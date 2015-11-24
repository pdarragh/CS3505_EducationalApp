
#include "socket.h"
#include <QDebug>

Socket::Socket()
{
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

}

void Socket::connect()
{

}

void Socket::disconnect()
{

}
