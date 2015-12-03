#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equationgenerator.h"
#include "dialog.h"
#include <QDebug>
#include <QString>
#include <QStandardItemModel>
#include <QIcon>


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

    connect(ui->manage_button, SIGNAL(clicked()), this, SLOT(manageStudent()));
    connect(ui->report_button, SIGNAL(clicked()), this, SLOT(manageStudent()));

   EquationGenerator* equations = new EquationGenerator;
   equations->generateAddition();
   equations->generateSubtraction();

   // TODO: Check if user is student or teacher
   teacher = true;

   // Creates the appropriate account display type for the user
   if (teacher)
   {
       ui->stackedWidget->setCurrentIndex(0);
       displayTeacherAccount();
   }
   else
   {
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
    QString str = name + "'s Class";

    ui->name_label->setText(str);

    // TODO: Server query to retrieve list of class's names and store inside students_list
}

/*
 * createClassTable()
 *
 * Displays the list of a teacher's students in a table format
 */
void MainWindow::createClassTable()
{
    // First part creates the empty table:
    QStandardItemModel *table_model = new QStandardItemModel(10, 2, this);
    table_model->setHorizontalHeaderItem(0, new QStandardItem(QString("Something 1")));
    table_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Something 2")));
    ui->table_view->setModel(table_model);

    // Second part creates the items that will be stored inside the table:
    //QIcon student_icon = new QIcon();
    //student_icon->addPixmap(QPixmap(":/new/prefix1/student_account.png"),QIcon::Normal,QIcon::On);
    //QStandardItem *student_icon = new QStandardItem(student_icon);

    QStandardItem *student1_name = new QStandardItem(QString("Name1"));

    // Third part adds those items to the table:
    table_model->setItem(0,1,student1_name);
}

void MainWindow::manageStudent()
{
    std::string student = ui->combo_box->currentText().toStdString();

    //TODO: bring up pop-up dialogue to manage student. Only option at this point is to delete.
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


}
