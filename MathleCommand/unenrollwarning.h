#ifndef UNENROLLWARNING_H
#define UNENROLLWARNING_H

#include <socket.h>
#include <QDialog>

namespace Ui {
class UnenrollWarning;
}

class UnenrollWarning : public QDialog
{
    Q_OBJECT

public:
    explicit UnenrollWarning(QWidget *parent = 0, QString someName = "");
    ~UnenrollWarning();
    Socket socket;

private:
    Ui::UnenrollWarning *ui;
    QString name;

private slots:
    void okayButton();
    void cancelButton();
};

#endif // UNENROLLWARNING_H
