#ifndef DIALOG_H
#define DIALOG_H
#include <QString>
#include <QDialog>
#include <socket.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    QString username;
    QString password;
    bool student;
    ~Dialog();

private slots:
    void onLoginPressed();
    void onNewUserPressed();
    void onCreateAccountPressed();

private:
    Ui::Dialog *ui;
    Socket socket;
};

#endif // DIALOG_H
