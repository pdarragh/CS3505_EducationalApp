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
    QLabel *level1Score;
    QPushButton *level2Button;
    QPushButton *level1Button;
    QLabel *level2Score;
    QPushButton *level3Button;
    QLabel *level3Score;
    QLabel *student_name_label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *AS_Resource;
    QLabel *MD_Resource;
    QLabel *welcome_label;
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
        stackedWidget->setGeometry(QRect(-1, -1, 699, 642));
        QFont font;
        font.setPointSize(15);
        stackedWidget->setFont(font);
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
        QFont font1;
        font1.setFamily(QStringLiteral("Courier"));
        table_view->setFont(font1);
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
        QFont font2;
        font2.setFamily(QStringLiteral("Chalkboard"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        name_label->setFont(font2);
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
        level1Score = new QLabel(page_2);
        level1Score->setObjectName(QStringLiteral("level1Score"));
        level1Score->setGeometry(QRect(440, 240, 51, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Chalkboard"));
        font3.setPointSize(18);
        level1Score->setFont(font3);
        level2Button = new QPushButton(page_2);
        level2Button->setObjectName(QStringLiteral("level2Button"));
        level2Button->setGeometry(QRect(220, 280, 121, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Chalkboard"));
        font4.setPointSize(16);
        level2Button->setFont(font4);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/christmas_star_filled.png"), QSize(), QIcon::Normal, QIcon::Off);
        level2Button->setIcon(icon3);
        level2Button->setIconSize(QSize(20, 20));
        level1Button = new QPushButton(page_2);
        level1Button->setObjectName(QStringLiteral("level1Button"));
        level1Button->setGeometry(QRect(220, 230, 121, 41));
        level1Button->setFont(font4);
        level1Button->setIcon(icon3);
        level1Button->setIconSize(QSize(20, 20));
        level2Score = new QLabel(page_2);
        level2Score->setObjectName(QStringLiteral("level2Score"));
        level2Score->setGeometry(QRect(440, 290, 51, 21));
        level2Score->setFont(font3);
        level3Button = new QPushButton(page_2);
        level3Button->setObjectName(QStringLiteral("level3Button"));
        level3Button->setGeometry(QRect(220, 330, 121, 41));
        level3Button->setFont(font4);
        level3Button->setIcon(icon3);
        level3Button->setIconSize(QSize(20, 20));
        level3Score = new QLabel(page_2);
        level3Score->setObjectName(QStringLiteral("level3Score"));
        level3Score->setGeometry(QRect(440, 340, 61, 21));
        level3Score->setFont(font3);
        student_name_label = new QLabel(page_2);
        student_name_label->setObjectName(QStringLiteral("student_name_label"));
        student_name_label->setGeometry(QRect(110, 110, 461, 51));
        QFont font5;
        font5.setFamily(QStringLiteral("Chalkboard"));
        font5.setPointSize(38);
        font5.setBold(true);
        font5.setWeight(75);
        student_name_label->setFont(font5);
        student_name_label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 180, 171, 20));
        label_2->setFont(font3);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 400, 391, 41));
        label_3->setFont(font3);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 450, 231, 31));
        QFont font6;
        font6.setFamily(QStringLiteral("Chalkboard"));
        font6.setPointSize(21);
        label_4->setFont(font6);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 530, 241, 31));
        QFont font7;
        font7.setFamily(QStringLiteral("Chalkboard"));
        font7.setPointSize(20);
        label_5->setFont(font7);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 60, 71, 71));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/home.png")));
        label_6->setAlignment(Qt::AlignCenter);
        AS_Resource = new QLabel(page_2);
        AS_Resource->setObjectName(QStringLiteral("AS_Resource"));
        AS_Resource->setGeometry(QRect(120, 485, 491, 31));
        QFont font8;
        font8.setPointSize(18);
        AS_Resource->setFont(font8);
        MD_Resource = new QLabel(page_2);
        MD_Resource->setObjectName(QStringLiteral("MD_Resource"));
        MD_Resource->setGeometry(QRect(120, 570, 491, 31));
        MD_Resource->setFont(font8);
        welcome_label = new QLabel(page_2);
        welcome_label->setObjectName(QStringLiteral("welcome_label"));
        welcome_label->setGeometry(QRect(110, 50, 461, 51));
        QFont font9;
        font9.setFamily(QStringLiteral("Chalkboard"));
        font9.setPointSize(30);
        font9.setBold(true);
        font9.setWeight(75);
        welcome_label->setFont(font9);
        welcome_label->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_2);
        page_3 = new GameWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        graphicsView = new QGraphicsView(page_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 60, 571, 411));
        title = new QLabel(page_3);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(190, 10, 231, 31));
        QFont font10;
        font10.setFamily(QStringLiteral("Forza"));
        font10.setPointSize(28);
        title->setFont(font10);
        equation = new QLabel(page_3);
        equation->setObjectName(QStringLiteral("equation"));
        equation->setGeometry(QRect(90, 500, 121, 41));
        QFont font11;
        font11.setPointSize(26);
        equation->setFont(font11);
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
        level1Score->setText(QString());
        level2Button->setText(QApplication::translate("MainWindow", "Level 2", 0));
        level1Button->setText(QApplication::translate("MainWindow", "Level 1", 0));
        level2Score->setText(QString());
        level3Button->setText(QApplication::translate("MainWindow", "Level 3", 0));
        level3Score->setText(QString());
        student_name_label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Start a New Game!", 0));
        label_3->setText(QApplication::translate("MainWindow", "Pssssss! Need help? Check out these resources!", 0));
        label_4->setText(QApplication::translate("MainWindow", "Addition & Subtraction:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Multiplication & Division:", 0));
        label_6->setText(QString());
        AS_Resource->setText(QString());
        MD_Resource->setText(QString());
        welcome_label->setText(QApplication::translate("MainWindow", "Welcome,", 0));
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
