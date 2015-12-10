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
    double posxStart;
    double gravity;
    double posy;
    int getEditorCanvasSize();

private:
    Ui::GameWidget *ui;
private slots:
    void on_answerButton_clicked();
    void update();
};

#endif // GAMEWIDGET_H
