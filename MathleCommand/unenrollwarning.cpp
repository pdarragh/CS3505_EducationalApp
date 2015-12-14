#include "unenrollwarning.h"
#include "ui_unenrollwarning.h"

#include <QDebug>

UnenrollWarning::UnenrollWarning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnenrollWarning)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), parentWidget(), SLOT(deleteStudent()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(cancelButton()));
}

UnenrollWarning::~UnenrollWarning()
{
    delete ui;
}

void UnenrollWarning::cancelButton()
{
    this->close();
}
