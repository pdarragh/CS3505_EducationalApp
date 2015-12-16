#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "equationgenerator.h"
#include "mathle.h"
#include "gameengine.h"
#include "socket.h"
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
    void startGame();
    QTimer* restartTimer;
    void setUsername(QString h);
    QString username;

private:
    Ui::GameWidget *ui;
    int current_level;
    int missed;
    int correct;
    Socket socket;
private slots:
    void update();
    void on_answerBox_returnPressed();
    void restart();
    void saveClicked();
};

#endif // GAMEWIDGET_H
