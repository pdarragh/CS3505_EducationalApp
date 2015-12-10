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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *name_label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableView *table_view;
    QComboBox *combo_box;
    QPushButton *manage_button;
    QLabel *label_3;
    QPushButton *report_button;
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
        name_label = new QLabel(page);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(40, 10, 591, 41));
        QFont font;
        font.setPointSize(23);
        name_label->setFont(font);
        name_label->setAlignment(Qt::AlignCenter);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(90, 60, 481, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 479, 449));
        table_view = new QTableView(scrollAreaWidgetContents);
        table_view->setObjectName(QStringLiteral("table_view"));
        table_view->setGeometry(QRect(0, 0, 480, 451));
        scrollArea->setWidget(scrollAreaWidgetContents);
        combo_box = new QComboBox(page);
        combo_box->setObjectName(QStringLiteral("combo_box"));
        combo_box->setGeometry(QRect(110, 530, 441, 26));
        manage_button = new QPushButton(page);
        manage_button->setObjectName(QStringLiteral("manage_button"));
        manage_button->setGeometry(QRect(560, 530, 91, 32));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 560, 91, 41));
        label_3->setWordWrap(true);
        report_button = new QPushButton(page);
        report_button->setObjectName(QStringLiteral("report_button"));
        report_button->setGeometry(QRect(330, 560, 61, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        report_button->setIcon(icon);
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
        manage_button->setText(QApplication::translate("MainWindow", "Unenroll", 0));
        label_3->setText(QApplication::translate("MainWindow", "View Class Progress...", 0));
        report_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
