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
#include <QtWidgets/QComboBox>
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
    QLineEdit *existing_password;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *existing_user;
    QPushButton *login_button;
    QLabel *label_4;
    QPushButton *new_account_button;
    QLabel *warning_label;
    QWidget *page_2;
    QLineEdit *new_user;
    QLineEdit *new_password;
    QComboBox *account_type;
    QPushButton *create_account_button;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *warning_label2;
    QLabel *label_8;

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
        existing_password = new QLineEdit(page);
        existing_password->setObjectName(QStringLiteral("existing_password"));
        existing_password->setGeometry(QRect(130, 140, 113, 21));
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
        existing_user = new QLineEdit(page);
        existing_user->setObjectName(QStringLiteral("existing_user"));
        existing_user->setGeometry(QRect(130, 100, 113, 21));
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
        new_user = new QLineEdit(page_2);
        new_user->setObjectName(QStringLiteral("new_user"));
        new_user->setGeometry(QRect(90, 50, 211, 21));
        new_password = new QLineEdit(page_2);
        new_password->setObjectName(QStringLiteral("new_password"));
        new_password->setGeometry(QRect(90, 110, 211, 21));
        account_type = new QComboBox(page_2);
        account_type->setObjectName(QStringLiteral("account_type"));
        account_type->setGeometry(QRect(160, 140, 151, 26));
        create_account_button = new QPushButton(page_2);
        create_account_button->setObjectName(QStringLiteral("create_account_button"));
        create_account_button->setGeometry(QRect(120, 180, 151, 32));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 20, 251, 20));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 80, 251, 20));
        label_6->setAlignment(Qt::AlignCenter);
        warning_label2 = new QLabel(page_2);
        warning_label2->setObjectName(QStringLiteral("warning_label2"));
        warning_label2->setGeometry(QRect(90, 220, 211, 51));
        warning_label2->setFont(font1);
        warning_label2->setAlignment(Qt::AlignCenter);
        warning_label2->setWordWrap(true);
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 150, 59, 16));
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
        create_account_button->setText(QApplication::translate("Dialog", "Create Account", 0));
        label_5->setText(QApplication::translate("Dialog", "Enter your desired username:", 0));
        label_6->setText(QApplication::translate("Dialog", "Enter your desired password:", 0));
        warning_label2->setText(QApplication::translate("Dialog", "Sorry, an account with this username already exists. Please try again.", 0));
        label_8->setText(QApplication::translate("Dialog", "I am a...", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
