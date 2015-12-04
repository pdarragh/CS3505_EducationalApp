#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include "socket.h"

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
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
   username =  ui->lineEdit->text();
   password =  ui->lineEdit_2->text();

   Socket socket;
   socket.connect();
   bool valid = socket.verifyUserLogin(username, password);

   if(!valid)
   {
       QPalette Pal(palette());
       Pal.setColor(QPalette::Background, Qt::red);
       this->setPalette(Pal);
   }
   /* Need this later
   else
   {
       this->accept();
   }
   */

   this->accept();
}
