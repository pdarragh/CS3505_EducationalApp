#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "socket.h"
#include "unenrollwarning.h"
#include "studentresults.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QString>
#include <QStandardItemModel>
#include <QIcon>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // this block is to demonstrate how to use the socket class
    // as well as test it. It can be deleted. You can uncomment and
    // run it to see if your sockets work.

    Dialog* login = new Dialog;
    if( login->exec() == QDialog::Accepted)
    {
        qDebug() << login->username;
    }
    else
    {
        qDebug() << "F YOU";
    }

    //connect all the buttons
    UnenrollWarning *warning = new UnenrollWarning(this);
    connect(ui->manage_button, SIGNAL(clicked()), warning, SLOT(show()));
    connect(ui->manage_button, SIGNAL(clicked()), this, SLOT(deleteStudent()));
    connect(ui->report_button, SIGNAL(clicked()), this, SLOT(generateStudentReport()));

   equations = new EquationGenerator;
   ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));

   //create the graphcis scene for the graphics view
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, getEditorCanvasSize(), getEditorCanvasSize());


   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(update()));
   timer->start(100);
    scene->addRect(posx, posy, 10, 10,
        QPen(), QBrush(Qt::SolidPattern));
  update();

   // TODO: Check if user is student or teacher
   teacher = true;

   // Creates the appropriate account display type for the user
   if (teacher)
   {
       //displayTeacherAccount();
       ui->stackedWidget->setCurrentIndex(0);
       displayTeacherAccount();
   }
   else
   {
       //displayStudentAccount();
       ui->stackedWidget->setCurrentIndex(1);
       displayStudentAccount();
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * displayTeacherAccount()
 *
 * Causes the display for a teacher to appear
 */
void MainWindow::displayTeacherAccount()
{
    // TODO: Store user name from database as a string
    std::string user_name = "Jane Smith";
    QString name = QString::fromStdString(user_name);
    QString str = name + "'s Students";

    ui->name_label->setText(str);

    createClassTable();
    populateComboBox();
}


/*
 *  retrieveClassInfo()
 *
 *  Used to fill the students_list vector with the names of students retrieved from the
 *  mySQL database.
 */
void MainWindow::retrieveClassInfo()
{
    if (!students_list.empty())
    {
        students_list.clear();
    }

    socket.connect();
    students_list = socket.getAllStudentResults();
    socket.disconnect();
}

/*
 * createClassTable()
 *
 * Displays the list of a teacher's students in a table format
 */
void MainWindow::createClassTable()
{
    // Makes sure nobody can mess around with the table
    ui->table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_view->setSelectionMode(QAbstractItemView::NoSelection);

    // First part creates the empty table:
    QStandardItemModel *table_model = new QStandardItemModel(10, 2, this);
    table_model->setHorizontalHeaderItem(0, new QStandardItem(QString("Level 1")));
    table_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Level 2")));
    table_model->setHorizontalHeaderItem(2, new QStandardItem(QString("Level 3")));
    table_model->setHorizontalHeaderItem(3, new QStandardItem(QString("Student Name")));
    ui->table_view->setModel(table_model);

    retrieveClassInfo();

    // Second part creates the items that will be stored inside the table and fills with names:
    for (int i = 0; i < students_list.size(); i++)
    {
        QStandardItem *student1_name = new QStandardItem(students_list[i].getUserName());

        std::stringstream s1;
        s1 << students_list[i].getLevelScore(1);
        QStandardItem *level1_score = new QStandardItem(QString::fromStdString(s1.str()));

        std::stringstream s2;
        s2 << students_list[i].getLevelScore(2);
        QStandardItem *level2_score = new QStandardItem(QString::fromStdString(s2.str()));

        std::stringstream s3;
        s3 << students_list[i].getLevelScore(3);
        QStandardItem *level3_score = new QStandardItem(QString::fromStdString(s3.str()));

        table_model->setItem(i, 0, level1_score);
        table_model->setItem(i, 1, level2_score);
        table_model->setItem(i, 2, level3_score);
        table_model->setItem(i, 3, student1_name);
    }

    ui->table_view->setColumnWidth(0, 100);
    ui->table_view->setColumnWidth(1, 100);
    ui->table_view->setColumnWidth(2, 100);
    ui->table_view->setColumnWidth(3, 180);
}

void MainWindow::populateComboBox()
{
    for (int i = 0; i < students_list.size(); i++)
    {
        ui->combo_box->addItem(students_list[i].getUserName());
    }
}

void MainWindow::deleteStudent()
{
    ui->table_view->model()->removeRow(ui->combo_box->currentIndex());
    ui->combo_box->removeItem(ui->combo_box->currentIndex());
}

void MainWindow::generateStudentReport()
{
    // TODO: open html report in browser

}

/*
 * displayStudentAccount()
 *
 * Causes the display for a student to appear. This should include buttons linking to the game's
 * levels and a display of that level's current high score; a large display area for the student's
 * name; a main menu button that opens the game in a new tab; and a button linking to the scoreboard.
 */
void MainWindow::displayStudentAccount()
{
//   QPushButton main_menu("Main Menu", this);
//   main_menu->setGeometry(QRect(QPoint(100, 150), QSize(100, 100)));


}

void MainWindow::displayGameWindow()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_answerButton_clicked()
{
    if(ui->answerBox->text() == QString::number(equations->answer))
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::green);
        ui->answerBox->setPalette(pal);
        timer->stop();
        ui->score->setText("10");
    }
    else
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::red);
        ui->answerBox->setPalette(pal);
    }
}

void MainWindow::update()
{

    if(scene->items().first()->pos().y() < ui->graphicsView->contentsRect().height())
    {
        //qDebug() << "fuf me";
        scene->items().first()->setPos(posx, posy++);
    }
    else
    {
        //qDebug() << "OVER";
    }


}

int MainWindow::getEditorCanvasSize()
{
    QRect rcontent = ui->graphicsView->contentsRect();
    return std::min(rcontent.width(), rcontent.height());
}

