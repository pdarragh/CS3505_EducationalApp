#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

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
    qDebug() << "Clicking Login";
   username =  ui->lineEdit->text();
   password =  ui->lineEdit_2->text();
}
