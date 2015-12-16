
#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "equationgenerator.h"
#include "mathle.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include <cmath>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    score(0)
{
    ui->setupUi(this);\
    gravity = 100; //Higher number = slower fall, cannot equal 0

    equations = new EquationGenerator;
    ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));

    //create the graphcis scene for the graphics view
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, getEditorCanvasSize(), getEditorCanvasSize());

    connect(ui->answerButton, SIGNAL(clicked()), this, SLOT(on_answerButton_clicked()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(60);

    //Create a bomb
    // 0,0,0    x,0,x               0,0,x
    // Regular  Regular with shift  Upward arc
    mathle1 = new Mathle;
    mathle1->makeMathle(0, 0, 5);
    mathle2 = new Mathle;
    mathle2->makeMathle(0, 0, 30);
    mathle3 = new Mathle;
    mathle3->makeMathle(120, 0, 125);
    mathle4 = new Mathle;
    mathle4->makeMathle(255, 0, 250);
    // Can only add one at the start
    scene->addRect(mathle1->posx, mathle1->posy, 10, 10,QPen(Qt::red), QBrush(Qt::SolidPattern));
    scene->addRect(mathle2->posx, mathle2->posy, 10, 10,QPen(Qt::green), QBrush(Qt::SolidPattern));
    scene->addRect(mathle3->posx, mathle3->posy, 10, 10,QPen(Qt::yellow), QBrush(Qt::SolidPattern));
    scene->addRect(mathle4->posx, mathle4->posy, 10, 10,QPen(), QBrush(Qt::SolidPattern));
//    for(int i = 0; i<100; i=i+10){
//        scene->addRect(i, 0, 10, 10,QPen(), QBrush(Qt::SolidPattern));
//    }
    GameWidget::update();
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_answerButton_clicked()
{
    if(ui->answerBox->text() != QString::number(equations->answer))
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::red);
        ui->answerBox->setPalette(pal);
        ui->answerBox->setText("");
    }
    else
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::green);
        ui->answerBox->setPalette(pal);
        scene->items().removeAt(0);
//        timer->stop();
        score += 10;
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    }
}

void GameWidget::update()
{
    int highestMathley = 0;
    //TODO: use iterator instead of for-loop
    for(int i=0; i<scene->items().length(); i++){
        if(scene->items()[i]->pos().y()>highestMathley)
        highestMathley = scene->items()[i]->pos().y();
    }
    // If a mathle has NOT hit the ground.
    if(highestMathley < ui->graphicsView->contentsRect().height()-10)
    {
        qDebug() << "fuf me";
        double oldy = mathle1->posy;
        // Don't ask why, but for some reason posx and posy have to be assigned here.
        // y = (x-offSet)^2 / slowDown;
        // THEY ARE PUT IN AT THE TOP FIRST
        // If offset and x > 250, send it left
        scene->items()[3]->setPos(mathle1->posx++, (mathle1->posy = pow(mathle1->posx-mathle1->posxStart, 2)/gravity));
        scene->items()[2]->setPos(mathle2->posx++, (mathle2->posy = pow(mathle2->posx-mathle2->posxStart, 2)/gravity));
        scene->items()[1]->setPos(mathle3->posx--, (mathle3->posy = pow(mathle3->posx-mathle3->posxStart, 2)/gravity));
        scene->items()[0]->setPos(mathle4->posx--, (mathle4->posy = pow(mathle4->posx-mathle4->posxStart, 2)/gravity));
//        scene->items()[3]->setPos(mathle5->posx--, (mathle5->posy = pow(mathle5->posx-mathle5->posxStart, 2)/gravity));

        qDebug() << mathle1->posx << mathle1->posy << mathle1->posy-oldy;
        qDebug() << mathle2->posx << mathle2->posy << mathle2->posxStart;
        qDebug() << mathle3->posx << mathle3->posy;
        qDebug() << mathle4->posx << mathle4->posy;

    }
    // Mathle hit the ground
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

void GameWidget::on_answerBox_returnPressed()
{
    if(ui->answerBox->text() != QString::number(equations->answer))
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::red);
        ui->answerBox->setPalette(pal);
        ui->answerBox->setText("");
    }
    else
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::green);
        ui->answerBox->setPalette(pal);
        timer->stop();
        score += 10;
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    }
}
