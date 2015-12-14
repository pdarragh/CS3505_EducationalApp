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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "GameWidget/gamewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableView *table_view;
    QLabel *name_label;
    QLabel *label;
    QComboBox *combo_box;
    QPushButton *report_button;
    QPushButton *manage_button;
    QPushButton *refresh_button;
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
    GameWidget *page_3;
    QGraphicsView *graphicsView;
    QLabel *title;
    QLabel *equation;
    QLineEdit *answerBox;
    QPushButton *answerButton;
    QLabel *score_label;
    QLabel *score;
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
        stackedWidget->setGeometry(QRect(10, -20, 700, 700));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(90, 120, 480, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 478, 449));
        table_view = new QTableView(scrollAreaWidgetContents);
        table_view->setObjectName(QStringLiteral("table_view"));
        table_view->setGeometry(QRect(0, 0, 480, 451));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        table_view->setFont(font);
        table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_view->setTabKeyNavigation(false);
        table_view->setProperty("showDropIndicator", QVariant(false));
        table_view->setDragDropOverwriteMode(false);
        table_view->setSelectionMode(QAbstractItemView::NoSelection);
        table_view->setShowGrid(true);
        table_view->setCornerButtonEnabled(false);
        scrollArea->setWidget(scrollAreaWidgetContents);
        name_label = new QLabel(page);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(170, 50, 341, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Chalkboard"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        name_label->setFont(font1);
        name_label->setAlignment(Qt::AlignCenter);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 50, 71, 51));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/classroom.png")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        combo_box = new QComboBox(page);
        combo_box->setObjectName(QStringLiteral("combo_box"));
        combo_box->setGeometry(QRect(100, 590, 341, 26));
        report_button = new QPushButton(page);
        report_button->setObjectName(QStringLiteral("report_button"));
        report_button->setGeometry(QRect(460, 580, 50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        report_button->setIcon(icon);
        report_button->setIconSize(QSize(30, 30));
        manage_button = new QPushButton(page);
        manage_button->setObjectName(QStringLiteral("manage_button"));
        manage_button->setGeometry(QRect(520, 580, 50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/delete_filled.png"), QSize(), QIcon::Normal, QIcon::Off);
        manage_button->setIcon(icon1);
        manage_button->setIconSize(QSize(30, 30));
        refresh_button = new QPushButton(page);
        refresh_button->setObjectName(QStringLiteral("refresh_button"));
        refresh_button->setGeometry(QRect(580, 580, 50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refresh_button->setIcon(icon2);
        refresh_button->setIconSize(QSize(30, 30));
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
        page_3 = new GameWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        graphicsView = new QGraphicsView(page_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 60, 571, 411));
        title = new QLabel(page_3);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(190, 10, 231, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Forza"));
        font2.setPointSize(28);
        title->setFont(font2);
        equation = new QLabel(page_3);
        equation->setObjectName(QStringLiteral("equation"));
        equation->setGeometry(QRect(90, 500, 121, 41));
        QFont font3;
        font3.setPointSize(26);
        equation->setFont(font3);
        answerBox = new QLineEdit(page_3);
        answerBox->setObjectName(QStringLiteral("answerBox"));
        answerBox->setGeometry(QRect(230, 510, 113, 21));
        answerButton = new QPushButton(page_3);
        answerButton->setObjectName(QStringLiteral("answerButton"));
        answerButton->setGeometry(QRect(360, 500, 115, 41));
        score_label = new QLabel(page_3);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(590, 60, 41, 16));
        score = new QLabel(page_3);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(640, 60, 31, 20));
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
        name_label->setText(QString());
        label->setText(QString());
#ifndef QT_NO_WHATSTHIS
        report_button->setWhatsThis(QApplication::translate("MainWindow", "Generate Report", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        report_button->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        report_button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        manage_button->setWhatsThis(QApplication::translate("MainWindow", "Unenroll Student", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        manage_button->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        manage_button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        refresh_button->setWhatsThis(QApplication::translate("MainWindow", "Unenroll Student", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        refresh_button->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        refresh_button->setText(QString());
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
        title->setText(QApplication::translate("MainWindow", "MathleCommand", 0));
        equation->setText(QString());
        answerButton->setText(QApplication::translate("MainWindow", "Answer", 0));
        score_label->setText(QApplication::translate("MainWindow", "Score:", 0));
        score->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
