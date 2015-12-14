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
    connect(ui->new_account_button, SIGNAL(pressed()), this, SLOT(onNewUserPressed()));
    connect(ui->create_account_button, SIGNAL(pressed()), this, SLOT(onCreateAccountPressed()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onLoginPressed()
{
   username =  ui->existing_user->text();
   password =  ui->existing_password->text();

   socket.connect();
   int account_type = socket.verifyUserLogin(username, password);
   if (account_type != 0)
   {
       this->accept();
       if (account_type == 1)
       {
           this->student = false;
       }
       else
       {
           this->student = true;
       }
   }
   else
   {
        ui->warning_label->show();
   }
   socket.disconnect();

}

void Dialog::onNewUserPressed()
{
    // Switches to create account screen
    ui->warning_label->hide();
    ui->warning_label2->hide();
    ui->stackedWidget->setCurrentIndex(1);
    ui->account_type->addItem("Student");
    ui->account_type->addItem("Teacher");
}

void Dialog::onCreateAccountPressed()
{
    username =  ui->new_user->text();
    password =  ui->new_password->text();

    socket.connect();
    if (ui->account_type->currentText() == QString::fromStdString("Student") && socket.createUser(username, password, true))
    {
        this->student = true;
        this->accept();
    }
    else if (ui->account_type->currentText() == QString::fromStdString("Teacher") && socket.createUser(username, password, false))
    {
        this->student = false;
        this->accept();
    }
    else
    {
        ui->warning_label2->show();
    }
    socket.disconnect();
}
