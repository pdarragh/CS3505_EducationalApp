#ifndef UNENROLLWARNING_H
#define UNENROLLWARNING_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class UnenrollWarning;
}

class UnenrollWarning : public QDialog
{
    Q_OBJECT

public:
    explicit UnenrollWarning(QWidget *parent = 0);
    ~UnenrollWarning();

private:
    Ui::UnenrollWarning *ui;

private slots:
    void cancelButton();
};

#endif // UNENROLLWARNING_H
