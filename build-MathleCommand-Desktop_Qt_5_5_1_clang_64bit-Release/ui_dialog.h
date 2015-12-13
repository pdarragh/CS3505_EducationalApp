/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *login_button;
    QLabel *label_4;
    QPushButton *new_account_button;
    QLabel *warning_label;
    QWidget *page_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 401, 301));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 140, 113, 21));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 71, 16));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 140, 71, 16));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 381, 41));
        QFont font;
        font.setFamily(QStringLiteral("Forza"));
        font.setPointSize(47);
        label->setFont(font);
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 100, 113, 21));
        login_button = new QPushButton(page);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(130, 200, 115, 32));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 240, 21, 16));
        new_account_button = new QPushButton(page);
        new_account_button->setObjectName(QStringLiteral("new_account_button"));
        new_account_button->setGeometry(QRect(100, 260, 181, 32));
        warning_label = new QLabel(page);
        warning_label->setObjectName(QStringLiteral("warning_label"));
        warning_label->setGeometry(QRect(50, 170, 281, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        warning_label->setFont(font1);
        warning_label->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label_2->setText(QApplication::translate("Dialog", "Username:", 0));
        label_3->setText(QApplication::translate("Dialog", "Password:", 0));
        label->setText(QApplication::translate("Dialog", "MathleCommand", 0));
        login_button->setText(QApplication::translate("Dialog", "Login", 0));
        label_4->setText(QApplication::translate("Dialog", "OR", 0));
        new_account_button->setText(QApplication::translate("Dialog", "Make New Account", 0));
        warning_label->setText(QApplication::translate("Dialog", "The username and/or password is incorrect.", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
