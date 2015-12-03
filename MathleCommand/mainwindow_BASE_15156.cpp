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

   // TODO: Check if user is student or teacher
   teacher = false;

   // Creates the appropriate account display type for the user
   if (teacher)
   {
       displayTeacherAccount();
   }
   else
   {
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
displayTeacherAccount()
{

}

/*
 * displayStudentAccount()
 *
 * Causes the display for a student to appear. This should include buttons linking to the game's
 * levels and a display of that level's current high score; a large display area for the student's
 * name; a main menu button that opens the game in a new tab; and a button linking to the scoreboard.
 */
displayStudentAccount()
{
   QPushButton main_menu("Main Menu", this);
   main_menu->setGeometry(QRect(QPoint(100, 150), QSize(100, 100)));


}
