#ifndef SOCKET
#define SOCKET

#include "mysql.h"
#include <QString>

class Socket
{

public:
    //Constructors
    Socket();
    ~Socket();

    //Methods
    void connect();
    void disconnect();
    bool verifyUserLogin(QString username, QString password);

private:
    MYSQL *connection;
    MYSQL mysql;

};



#endif // SOCKET
