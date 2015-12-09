#ifndef SOCKET
#define SOCKET

#include "mysql.h"
#include "studentresults.h"
#include <QString>
#include <vector>

class Socket
{

public:
    enum AccountType { Invalid=0, Teacher, Student };

    //Constructors
    Socket();
    ~Socket();

    //Methods
    void connect();
    void disconnect();
    int verifyUserLogin(QString username, QString password);
    bool createUser(QString username, QString password, bool isStudent);
    StudentResults getStudentResults(QString username);
    std::vector<StudentResults> getAllStudentResults();
    void recordStudentResult(QString username, int level, int score, int misses);

private:
    MYSQL *connection;
    MYSQL mysql;

};



#endif // SOCKET
