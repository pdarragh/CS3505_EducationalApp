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
    void retrieveClassInfo();
    void createClassTable();
    void populateComboBox();
    bool teacher;
    std::vector<std::string> students_list;

private slots:
    void deleteStudent();
    void generateStudentReport();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
