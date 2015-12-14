#ifndef UNENROLLWARNING_H
#define UNENROLLWARNING_H

#include <socket.h>
#include <QDialog>
#include <QString>

namespace Ui {
class UnenrollWarning;
}

class UnenrollWarning : public QDialog
{
    Q_OBJECT

public:
    explicit UnenrollWarning(QWidget *parent = 0);
    ~UnenrollWarning();
    Socket socket;
    QString name;

private:
    Ui::UnenrollWarning *ui;

private slots:
    void cancelButton();
};

#endif // UNENROLLWARNING_H
