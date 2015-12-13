#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPalette Pal(palette());

    // set black background
    Pal.setColor(QPalette::Background, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    ui->stackedWidget->setCurrentIndex(0);
    ui->warning_label->hide();
    connect(ui->login_button, SIGNAL(pressed()), this, SLOT(onLoginPressed()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onLoginPressed()
{
   username =  ui->lineEdit->text();
   password =  ui->lineEdit_2->text();

   socket.connect();
   int account_type = socket.verifyUserLogin(username, password);
   if (account_type != 0)
   {
       this->accept();
   }
   else
   {
        ui->warning_label->show();
   }
   socket.disconnect();

}

void Dialog::onCreateAccountPressed()
{
    ui->stackedWidget->setCurrentIndex(1);
}
