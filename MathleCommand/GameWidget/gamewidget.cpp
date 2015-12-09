#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "equationgenerator.h"
#include <QGraphicsRectItem>
#include <QDebug>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    equations = new EquationGenerator;
    ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));

    //create the graphcis scene for the graphics view
     scene = new QGraphicsScene;
     ui->graphicsView->setScene(scene);
     ui->graphicsView->setSceneRect(0, 0, getEditorCanvasSize(), getEditorCanvasSize());


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
     scene->addRect(posx, posy, 10, 10,
         QPen(), QBrush(Qt::SolidPattern));
   update();
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::update()
{

    if(scene->items().first()->pos().y() < ui->graphicsView->contentsRect().height())
    {
        qDebug() << "fuf me";
        scene->items().first()->setPos(posx, posy++);
    }
    else
    {
        qDebug() << "OVER";
    }


}

int GameWidget::getEditorCanvasSize()
{
    QRect rcontent = ui->graphicsView->contentsRect();
    return std::min(rcontent.width(), rcontent.height());
}
