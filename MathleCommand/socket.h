#ifndef SOCKET
#define SOCKET

#include <QtSql>
//#include <QtSql/QMYSQLDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

class Socket
{

public:

    //Constructors
    Socket();

    //Methods
    void connect();
    //bool login(QString username, QString password);
    void disconnect();

    //Variables
    QSqlDatabase db;

};



#endif // SOCKET

