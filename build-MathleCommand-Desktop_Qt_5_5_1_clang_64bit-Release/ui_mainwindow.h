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
    QLabel *studentNameLabel;
    QPushButton *level1Button;
    QPushButton *level2Button;
    QPushButton *level3Button;
    QPushButton *goToScoreBoardButton;
    QPushButton *logOutButton;
    QLabel *highScoreLabel;
    QLabel *level1Score;
    QLabel *level2Score;
    QLabel *level3Score;
    QWidget *page_2;
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
        studentNameLabel = new QLabel(page);
        studentNameLabel->setObjectName(QStringLiteral("studentNameLabel"));
        studentNameLabel->setGeometry(QRect(80, 150, 241, 61));
        studentNameLabel->setStyleSheet(QStringLiteral("font: 26pt \"MS Shell Dlg 2\";"));
        level1Button = new QPushButton(page);
        level1Button->setObjectName(QStringLiteral("level1Button"));
        level1Button->setGeometry(QRect(450, 120, 75, 23));
        level2Button = new QPushButton(page);
        level2Button->setObjectName(QStringLiteral("level2Button"));
        level2Button->setGeometry(QRect(450, 160, 75, 23));
        level3Button = new QPushButton(page);
        level3Button->setObjectName(QStringLiteral("level3Button"));
        level3Button->setGeometry(QRect(450, 200, 75, 23));
        goToScoreBoardButton = new QPushButton(page);
        goToScoreBoardButton->setObjectName(QStringLiteral("goToScoreBoardButton"));
        goToScoreBoardButton->setGeometry(QRect(490, 320, 131, 23));
        logOutButton = new QPushButton(page);
        logOutButton->setObjectName(QStringLiteral("logOutButton"));
        logOutButton->setGeometry(QRect(20, 20, 75, 23));
        highScoreLabel = new QLabel(page);
        highScoreLabel->setObjectName(QStringLiteral("highScoreLabel"));
        highScoreLabel->setGeometry(QRect(560, 80, 51, 20));
        level1Score = new QLabel(page);
        level1Score->setObjectName(QStringLiteral("level1Score"));
        level1Score->setGeometry(QRect(560, 120, 47, 13));
        level2Score = new QLabel(page);
        level2Score->setObjectName(QStringLiteral("level2Score"));
        level2Score->setGeometry(QRect(560, 160, 47, 13));
        level3Score = new QLabel(page);
        level3Score->setObjectName(QStringLiteral("level3Score"));
        level3Score->setGeometry(QRect(560, 210, 47, 13));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
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
        studentNameLabel->setText(QApplication::translate("MainWindow", "Student Name", 0));
        level1Button->setText(QApplication::translate("MainWindow", "Level 1", 0));
        level2Button->setText(QApplication::translate("MainWindow", "Level 2", 0));
        level3Button->setText(QApplication::translate("MainWindow", "Level 3", 0));
        goToScoreBoardButton->setText(QApplication::translate("MainWindow", "Go To Scoreboard", 0));
        logOutButton->setText(QApplication::translate("MainWindow", "Log Out", 0));
        highScoreLabel->setText(QApplication::translate("MainWindow", "High Score", 0));
        level1Score->setText(QApplication::translate("MainWindow", "0", 0));
        level2Score->setText(QApplication::translate("MainWindow", "0", 0));
        level3Score->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
