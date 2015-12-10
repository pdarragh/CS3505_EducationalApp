#include "unenrollwarning.h"
#include "ui_unenrollwarning.h"

UnenrollWarning::UnenrollWarning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnenrollWarning)
{
    ui->setupUi(this);

    ui->button
}

UnenrollWarning::~UnenrollWarning()
{
    delete ui;
}
