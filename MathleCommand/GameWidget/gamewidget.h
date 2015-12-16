#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QQueue>
#include "equationgenerator.h"
#include "mathle.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

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
    double gravity;
    int lives;
    int count;
    int getEditorCanvasSize();
    int score;

private:
    Ui::GameWidget *ui;
    QQueue<Mathle*> mathleQueue;
    QQueue<QGraphicsRectItem*> sceneQueue;
private slots:
    void on_answerButton_clicked();
    void update();
    void on_answerBox_returnPressed();
};

#endif // GAMEWIDGET_H
