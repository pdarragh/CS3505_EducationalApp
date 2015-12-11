#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equationgenerator.h"
#include <QTimer>
#include <QGraphicsScene>

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
    QGraphicsScene* scene;
     QTimer *timer;
     int posx;
     int posy;
    std::vector<std::string> students_list;
    void displayTeacherAccount();
    void retrieveClassInfo();
    void createClassTable();
    void setStudentScores();
    void populateComboBox();
    void displayStudentAccount();
    void displayGameWindow();
    int getEditorCanvasSize();
    bool teacher;

private slots:
    void deleteStudent();
    void generateStudentReport();
    void on_answerButton_clicked();

    //void on_page_3_destroyed();
    void update();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
