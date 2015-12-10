#ifndef UNENROLLWARNING_H
#define UNENROLLWARNING_H

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
};

#endif // UNENROLLWARNING_H
