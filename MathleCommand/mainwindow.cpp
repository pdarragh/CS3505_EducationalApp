#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Dialog* login = new Dialog;
    if( login->exec() == QDialog::Accepted)
    {
        qDebug() << login->username;
    }
    else
    {
        qDebug() << "F YOU";
    }

    displayGameWindow();

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

   // In future this will be triggered by a button in the student account window


   // Creates the appropriate account display type for the user
   /*if (teacher)
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
   }*/
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
        qDebug() << "fuf me";
        scene->items().first()->setPos(posx, posy++);
    }
    else
    {
        qDebug() << "OVER";
    }


}

int MainWindow::getEditorCanvasSize()
{
    QRect rcontent = ui->graphicsView->contentsRect();
    return std::min(rcontent.width(), rcontent.height());
}

