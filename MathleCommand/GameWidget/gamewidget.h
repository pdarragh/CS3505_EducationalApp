#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "equationgenerator.h"
#include "mathle.h"
#include "gameengine.h"
#include "sstream"
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
    //EquationGenerator* equations;
    QGraphicsScene* scene;
    QTimer *timer;
    Mathle* mathle;
    GameEngine* engine;
    void checkLevelAndSetEquation();
    double gravity;
    int getEditorCanvasSize();
    int score;
    void setLevel(int level);

private:
    Ui::GameWidget *ui;
    int current_level;
private slots:
    void on_answerButton_clicked();
    void update();
    void on_answerBox_returnPressed();
};

#endif // GAMEWIDGET_H
