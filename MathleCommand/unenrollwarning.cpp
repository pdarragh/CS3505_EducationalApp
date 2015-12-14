#include "unenrollwarning.h"
#include "ui_unenrollwarning.h"

UnenrollWarning::UnenrollWarning(QWidget *parent, QString studentName) :
    QDialog(parent),
    ui(new Ui::UnenrollWarning)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(okayButton()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(cancelButton()));
}

UnenrollWarning::~UnenrollWarning()
{
    delete ui;
}

void UnenrollWarning::okayButton()
{
    socket.connect();
    socket.deleteUser(this->name);
    socket.disconnect();
}

void UnenrollWarning::cancelButton()
{
    this->close();
}
