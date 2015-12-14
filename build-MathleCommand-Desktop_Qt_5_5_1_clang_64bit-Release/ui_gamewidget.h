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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QLabel *label;
    QGraphicsView *graphicsView;
    QLabel *score_label;
    QLabel *score;
    QLabel *title;
    QLineEdit *answerBox;
    QPushButton *answerButton;
    QLabel *equation;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(700, 700);
        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 600, 700, 100));
        label->setStyleSheet(QStringLiteral("background-color: green;"));
        graphicsView = new QGraphicsView(GameWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 701, 600));
        graphicsView->setStyleSheet(QStringLiteral("background-color: lightblue;"));
        score_label = new QLabel(GameWidget);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(570, 70, 41, 16));
        score = new QLabel(GameWidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(620, 70, 51, 16));
        title = new QLabel(GameWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(200, 615, 321, 41));
        QFont font;
        font.setPointSize(33);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);
        answerBox = new QLineEdit(GameWidget);
        answerBox->setObjectName(QStringLiteral("answerBox"));
        answerBox->setGeometry(QRect(210, 520, 113, 21));
        answerButton = new QPushButton(GameWidget);
        answerButton->setObjectName(QStringLiteral("answerButton"));
        answerButton->setGeometry(QRect(360, 510, 121, 41));
        equation = new QLabel(GameWidget);
        equation->setObjectName(QStringLiteral("equation"));
        equation->setGeometry(QRect(200, 470, 291, 31));
        QFont font1;
        font1.setPointSize(22);
        equation->setFont(font1);
        equation->setAlignment(Qt::AlignCenter);

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "GameWidget", 0));
        label->setText(QString());
        score_label->setText(QApplication::translate("GameWidget", "Score:", 0));
        score->setText(QString());
        title->setText(QApplication::translate("GameWidget", "MathleCommand", 0));
        answerButton->setText(QApplication::translate("GameWidget", "Answer", 0));
        equation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
