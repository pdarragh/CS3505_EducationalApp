/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(700, 700);
        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 600, 700, 100));
        label->setStyleSheet(QStringLiteral("background-color: green;"));
        label_2 = new QLabel(GameWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 700, 700));
        label_2->setStyleSheet(QStringLiteral("background-color: skyblue;"));
        label_2->raise();
        label->raise();

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "GameWidget", 0));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
