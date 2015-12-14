/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
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
    QLineEdit *answerBox;
    QLabel *score_label;
    QLabel *equation;
    QGraphicsView *graphicsView;
    QLabel *title;
    QLabel *score;
    QPushButton *answerButton;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(700, 700);
        GameWidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 600, 700, 100));
        label->setStyleSheet(QStringLiteral("background-color: green;"));
        answerBox = new QLineEdit(GameWidget);
        answerBox->setObjectName(QStringLiteral("answerBox"));
        answerBox->setGeometry(QRect(220, 520, 113, 21));
        answerBox->setMouseTracking(false);
        answerBox->setAutoFillBackground(true);
        answerBox->setStyleSheet(QStringLiteral(""));
        score_label = new QLabel(GameWidget);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(600, 70, 41, 16));
        equation = new QLabel(GameWidget);
        equation->setObjectName(QStringLiteral("equation"));
        equation->setGeometry(QRect(100, 510, 121, 41));
        QFont font;
        font.setPointSize(26);
        equation->setFont(font);
        graphicsView = new QGraphicsView(GameWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 701, 601));
        graphicsView->setStyleSheet(QLatin1String("background-color: skyblue\n"
""));
        title = new QLabel(GameWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(210, 630, 281, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Forza"));
        font1.setPointSize(28);
        title->setFont(font1);
        title->setStyleSheet(QStringLiteral("QLineEdit { color: red }"));
        score = new QLabel(GameWidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(650, 70, 31, 20));
        answerButton = new QPushButton(GameWidget);
        answerButton->setObjectName(QStringLiteral("answerButton"));
        answerButton->setGeometry(QRect(370, 510, 115, 41));
        graphicsView->raise();
        label->raise();
        answerBox->raise();
        score_label->raise();
        equation->raise();
        title->raise();
        score->raise();
        answerButton->raise();
        QWidget::setTabOrder(answerBox, answerButton);
        QWidget::setTabOrder(answerButton, graphicsView);

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "GameWidget", 0));
        label->setText(QString());
        score_label->setText(QApplication::translate("GameWidget", "Score:", 0));
        equation->setText(QString());
        title->setText(QApplication::translate("GameWidget", "MathleCommand", 0));
        score->setText(QString());
        answerButton->setText(QApplication::translate("GameWidget", "Answer", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
