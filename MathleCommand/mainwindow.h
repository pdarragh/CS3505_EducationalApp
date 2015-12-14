#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equationgenerator.h"
#include "socket.h"
#include "dialog.h"
#include "unenrollwarning.h"
#include <QTimer>
#include <QString>
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
    Dialog* login;
    ~MainWindow();
    EquationGenerator* equations;
    QGraphicsScene* scene;
    QTimer *timer;
    int posx;
    int posy;
    void displayTeacherAccount();
    void retrieveClassInfo();
    void createClassTable();
    void populateComboBox();
    void displayStudentAccount();
    void displayGameWindow();

private slots:
    void generateStudentReport();
    void on_answerButton_clicked();
    void deleteStudent();
    void update();
    void on_refresh_button_clicked();
    void on_combo_box_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    UnenrollWarning *warning;
    std::vector<StudentResults> students_list;
    StudentResults student_high_scores;
    bool teacher;
    Socket socket;
    int getEditorCanvasSize();
};

#endif // MAINWINDOW_H
