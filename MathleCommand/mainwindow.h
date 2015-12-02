#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equationgenerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //enum EquationType { Addition, Subtraction, Multiplication, Divison };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    EquationGenerator* equations;
    void displayTeacherAccount();
    void displayStudentAccount();
    void displayGameWindow();
    bool teacher;

private slots:
    void on_answerButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
