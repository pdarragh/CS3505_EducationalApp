#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "socket.h"
#include "studentresults.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QStandardItemModel>
#include <QIcon>
#include <QFile>
#include <QFileInfo>
#include <QString>
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

    login = new Dialog;
    if( login->exec() == QDialog::Accepted)
    {
        qDebug() << login->username;
    }
    else
    {
        qDebug() << "F YOU";
    }

    //connect all the buttons
    this->warning = new UnenrollWarning(this);
    this->warning->hide();
    connect(ui->manage_button, SIGNAL(clicked()), warning, SLOT(show()));
    connect(ui->report_button, SIGNAL(clicked()), this, SLOT(generateStudentReport()));
    connect(ui->refresh_button, SIGNAL(clicked()), this, SLOT(on_refresh_button_clicked()));
    connect(ui->combo_box, SIGNAL(currentTextChanged(QString)), this, SLOT(on_combo_box_currentTextChanged(QString)));

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

   // Creates the appropriate account display type for the user
   if (!(login->student))
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
    // Displays user name
    QString name = login->username;
    QString str = name + "'s Students";
    ui->name_label->setText(str);

    // Fills in the table of students and combo box to select a student
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
        s1 << students_list[i].getLevelAverageScore(1);
        QStandardItem *level1_score = new QStandardItem(QString::fromStdString(s1.str()));

        std::stringstream s2;
        s2 << students_list[i].getLevelAverageScore(2);
        QStandardItem *level2_score = new QStandardItem(QString::fromStdString(s2.str()));

        std::stringstream s3;
        s3 << students_list[i].getLevelAverageScore(3);
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
    qDebug() << "Deleting " + ui->combo_box->currentText() + " FOREVER";
    socket.connect();
    socket.deleteUser(ui->combo_box->currentText());
    socket.disconnect();
}

void MainWindow::generateStudentReport()
{
    // Update class info
    retrieveClassInfo();
    // TODO: open html report in browser

    QFile file("./report.html");
    QFileInfo fileinfo(file.fileName());
    QString filepath(fileinfo.fileName());
    qDebug() << "filepath: " << filepath << "";
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "error: failed to open file for writing";
        return;
    }

    QTextStream report(&file);

    // HTML head
    report << html_helper(0, "<!DOCTYPE html>");
    report << html_helper(0, "<html>");

    // Begin table
    report << html_helper(1, "<table>");

    // Table head
    report << html_helper(2, "<thead>");
    report << html_helper(3, "<tr>");
    report << html_helper(4, "<th><!-- Space for student name/level marker --></th>");
    report << html_helper(4, "<th>Attempts</th>");
    report << html_helper(4, "<th>Average Score</th>");
    report << html_helper(4, "<th>Average Misses/Attempt</th>");
    report << html_helper(3, "</tr>");
    report << html_helper(2, "</thead>");

    // Table body
    report << html_helper(2, "<tbody>");
    // Each student
    for (const StudentResults &student : students_list)
    {
        // Aggregate totals
        report << html_helper(3, "<tr>");
        report << html_helper(4, "<td>" + student.getUserName() + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getTotalAttempts()) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getTotalAverageScore()) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getTotalAverageMisses()) + "</td>");
        report << html_helper(3, "</tr>");
        // Level 1
        report << html_helper(3, "<tr>");
        report << html_helper(4, "<td>Level 1</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAttempts(1)) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAverageScore(1)) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAverageMisses(1)) + "</td>");
        report << html_helper(3, "</tr>");
        // Level 2
        report << html_helper(3, "<tr>");
        report << html_helper(4, "<td>Level 2</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAttempts(2)) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAverageScore(2)) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAverageMisses(2)) + "</td>");
        report << html_helper(3, "</tr>");
        // Level 3
        report << html_helper(3, "<tr>");
        report << html_helper(4, "<td>Level 3</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAttempts(3)) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAverageScore(3)) + "</td>");
        report << html_helper(4, "<td>" + QString::number(student.getLevelAverageMisses(3)) + "</td>");
        report << html_helper(3, "</tr>");
    }
    report << html_helper(2, "</tbody>");

    // Finish table
    report << html_helper(1, "</table>");

    // Finish the document
    report << html_helper(0, "</html>");
}

QString MainWindow::html_helper(int indentation, QString text)
{
    return QString(indentation * 4, ' ') + text + QString("\n");
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
    // Displays user name
    QString name = login->username;
    QString str = name + "!";
    ui->student_name_label->setText(str);

    // Fills in level high scores
    socket.connect();
    student_high_scores = socket.getStudentResults(login->username);
    socket.disconnect();
    std::stringstream score1;
    score1 << student_high_scores.getLevelMaxScore(1);
    ui->level1Score->setText(QString::fromStdString(score1.str()));
    std::stringstream score2;
    score2 << student_high_scores.getLevelMaxScore(2);
    ui->level2Score->setText(QString::fromStdString(score2.str()));
    std::stringstream score3;
    score3 << student_high_scores.getLevelMaxScore(3);
    ui->level3Score->setText(QString::fromStdString(score3.str()));
}


void MainWindow::on_refresh_button_clicked()
{
    createClassTable();
    ui->combo_box->clear();
    populateComboBox();
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

void MainWindow::on_combo_box_currentTextChanged(const QString &arg1)
{
     this->warning = new UnenrollWarning(this);
     qDebug() << "INDEX CHANGED TO " + arg1;
}

void MainWindow::on_level1Button_clicked()
{
    myGame = new GameWidget(this);
    myGame->show();
}
