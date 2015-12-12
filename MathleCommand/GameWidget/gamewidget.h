#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "equationgenerator.h"
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
    double posx;
    double posy;
    int getEditorCanvasSize();

private:
    Ui::GameWidget *ui;
private slots:
    void on_answerButton_clicked();
    void update();
    void on_answerBox_returnPressed();
    void on_answerBox_cursorPositionChanged(int arg1, int arg2);
};

#endif // GAMEWIDGET_H
