#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayTeacherAccount();
    void displayStudentAccount();
    void createClassTable();
    void manageStudent();
    void generateStudentReport();
    bool teacher;
    std::vector<std::string> students_list;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
