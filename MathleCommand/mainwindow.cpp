#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equationgenerator.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   EquationGenerator* equations = new EquationGenerator;
   equations->generateAddition();
   equations->generateSubtraction();
}


MainWindow::~MainWindow()
{
    delete ui;
}
