/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *logOutButton;
    QLabel *level1Score;
    QPushButton *level2Button;
    QPushButton *level1Button;
    QLabel *studentNameLabel;
    QLabel *level2Score;
    QPushButton *level3Button;
    QLabel *level3Score;
    QPushButton *goToScoreBoardButton;
    QLabel *highScoreLabel;
    QWidget *page_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 700, 700));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        logOutButton = new QPushButton(page_2);
        logOutButton->setObjectName(QStringLiteral("logOutButton"));
        logOutButton->setGeometry(QRect(0, 0, 75, 23));
        level1Score = new QLabel(page_2);
        level1Score->setObjectName(QStringLiteral("level1Score"));
        level1Score->setGeometry(QRect(480, 40, 47, 13));
        level2Button = new QPushButton(page_2);
        level2Button->setObjectName(QStringLiteral("level2Button"));
        level2Button->setGeometry(QRect(370, 80, 75, 23));
        level1Button = new QPushButton(page_2);
        level1Button->setObjectName(QStringLiteral("level1Button"));
        level1Button->setGeometry(QRect(370, 40, 75, 23));
        studentNameLabel = new QLabel(page_2);
        studentNameLabel->setObjectName(QStringLiteral("studentNameLabel"));
        studentNameLabel->setGeometry(QRect(0, 70, 241, 61));
        studentNameLabel->setStyleSheet(QStringLiteral("font: 26pt \"MS Shell Dlg 2\";"));
        level2Score = new QLabel(page_2);
        level2Score->setObjectName(QStringLiteral("level2Score"));
        level2Score->setGeometry(QRect(480, 80, 47, 13));
        level3Button = new QPushButton(page_2);
        level3Button->setObjectName(QStringLiteral("level3Button"));
        level3Button->setGeometry(QRect(370, 120, 75, 23));
        level3Score = new QLabel(page_2);
        level3Score->setObjectName(QStringLiteral("level3Score"));
        level3Score->setGeometry(QRect(480, 130, 47, 13));
        goToScoreBoardButton = new QPushButton(page_2);
        goToScoreBoardButton->setObjectName(QStringLiteral("goToScoreBoardButton"));
        goToScoreBoardButton->setGeometry(QRect(410, 240, 131, 23));
        highScoreLabel = new QLabel(page_2);
        highScoreLabel->setObjectName(QStringLiteral("highScoreLabel"));
        highScoreLabel->setGeometry(QRect(480, 0, 51, 20));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        logOutButton->setText(QApplication::translate("MainWindow", "Log Out", 0));
        level1Score->setText(QApplication::translate("MainWindow", "0", 0));
        level2Button->setText(QApplication::translate("MainWindow", "Level 2", 0));
        level1Button->setText(QApplication::translate("MainWindow", "Level 1", 0));
        studentNameLabel->setText(QApplication::translate("MainWindow", "Student Name", 0));
        level2Score->setText(QApplication::translate("MainWindow", "0", 0));
        level3Button->setText(QApplication::translate("MainWindow", "Level 3", 0));
        level3Score->setText(QApplication::translate("MainWindow", "0", 0));
        goToScoreBoardButton->setText(QApplication::translate("MainWindow", "Go To Scoreboard", 0));
        highScoreLabel->setText(QApplication::translate("MainWindow", "High Score", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
