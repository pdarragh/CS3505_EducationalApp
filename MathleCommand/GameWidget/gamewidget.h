#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "equationgenerator.h"
#include "mathle.h"
#include <QTimer>
#include <QGraphicsScene>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();
    EquationGenerator* equations;
    QGraphicsScene* scene;
    QTimer *timer;
    Mathle* mathle1;
    Mathle* mathle2;
    Mathle* mathle3;
    Mathle* mathle4;
    double gravity;
    int getEditorCanvasSize();
    int score;

private:
    Ui::GameWidget *ui;
private slots:
    void on_answerButton_clicked();
    void update();
    void on_answerBox_returnPressed();
};

#endif // GAMEWIDGET_H
