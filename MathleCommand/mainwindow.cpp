#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equationgenerator.h"
#include "dialog.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Dialog* login = new Dialog;
    if( login->exec() == QDialog::Accepted)
    {

        qDebug() << login->username;
        //return;
    }

   EquationGenerator* equations = new EquationGenerator;
   equations->generateAddition();
   equations->generateSubtraction();
}


MainWindow::~MainWindow()
{
    delete ui;
}
