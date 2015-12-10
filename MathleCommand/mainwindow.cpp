#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equationgenerator.h"
#include "dialog.h"
#include "unenrollwarning.h"
//#include "socket.h"
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

    UnenrollWarning *warning = new UnenrollWarning(this);
    connect(ui->manage_button, SIGNAL(clicked()), warning, SLOT(show()));

    connect(ui->manage_button, SIGNAL(clicked()), this, SLOT(deleteStudent()));
    connect(ui->report_button, SIGNAL(clicked()), this, SLOT(generateStudentReport()));

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
    QString str = name + "'s Students";

    ui->name_label->setText(str);

    //retrieveClassInfo();
    createClassTable();
    populateComboBox();

    // TODO: Server query to retrieve list of class's names and store inside students_list
}


/*
 *  retrieveClassInfo()
 *
 *  Used to fill the students_list vector with the names of students retrieved from the
 *  mySQL database.
 */
void retrieveClassInfo()
{
    
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
    table_model->setHorizontalHeaderItem(0, new QStandardItem(QString("Level 1")));
    table_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Level 2")));
    table_model->setHorizontalHeaderItem(2, new QStandardItem(QString("Level 3")));
    table_model->setHorizontalHeaderItem(3, new QStandardItem(QString("Student Name")));
    ui->table_view->setModel(table_model);

    // To be deleted:
    students_list.push_back("Ned Stark");
    students_list.push_back("Sansa Stark");
    students_list.push_back("Arya Stark");
    students_list.push_back("Rob Stark");
    students_list.push_back("Brandon Stark");
    students_list.push_back("Rickon Stark");
    students_list.push_back("Catlyn Stark");
    students_list.push_back("Jon Snow");
    students_list.push_back("Daenerys Targaryen");
    students_list.push_back("Viserys Targaryen");
    students_list.push_back("Khal Drogo");
    students_list.push_back("Robert Baratheon");
    students_list.push_back("Stannis Baratheon");
    students_list.push_back("Renly Baratheon");
    students_list.push_back("Tywin Lannister");
    students_list.push_back("Tyrion Lannister");
    students_list.push_back("Cersei Lannister");
    students_list.push_back("Jaime Lannister");
    students_list.push_back("Joffrey Lannister");
    students_list.push_back("Marcella Lannister");
    students_list.push_back("Tommen Lannister");

    // Second part creates the items that will be stored inside the table and fills with names:
    for (int i = 0; i < students_list.size(); i++)
    {
        QStandardItem *student1_name = new QStandardItem(QString::fromStdString(students_list[i]));
        table_model->setItem(i, 3, student1_name);
        //setStudentScores(students_list[i], i);
    }

    ui->table_view->setColumnWidth(0, 100);
    ui->table_view->setColumnWidth(1, 100);
    ui->table_view->setColumnWidth(2, 100);
    ui->table_view->setColumnWidth(3, 180);
}

void setStudentScores(std::string name, int row)
{
    /*Sockets::StudentResults results getStudentResults(name);
    QStandardItem *level1_score = new QStandardItem(QString::fromStdString(results.getLevelScore(1));
    QStandardItem *level2_score = new QStandardItem(QString::fromStdString(results.getLevelScore(2));
    QStandardItem *level3_score = new QStandardItem(QString::fromStdString(results.getLevelScore(3));
    table_model->setItem(row, 0, level1_score);
    table_model->setItem(row, 1, level2_score);
    table_model->setItem(row, 2, level3_score);*/
}

void MainWindow::populateComboBox()
{
    for (int i = 0; i < students_list.size(); i++)
    {
        ui->combo_box->addItem(QString::fromStdString(students_list[i]));
    }
}

void MainWindow::deleteStudent()
{


    /*ui->table_view->model()->removeRow(ui->combo_box->currentIndex());
    ui->combo_box->removeItem(ui->combo_box->currentIndex());*/



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
