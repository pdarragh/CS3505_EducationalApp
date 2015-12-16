#include <stdlib.h>
#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "equationgenerator.h"
#include "mathle.h"
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QDebug>
#include <cmath>
#include <QBitmap>
#include <QMutex>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    score(0),
    lives(3),
    count(10),
    mathleQueue(QQueue<Mathle*>()),
    sceneQueue(QQueue<QGraphicsRectItem*>())
{
    ui->setupUi(this);
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
    timer->start(100);


    //scene->addPixmap(QPixmap(":/new/prefix1/amissile.png"));
    //sceneQueue.head()->setPos(mathle1->posx,mathle1->posy);
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
        //timer->stop();
        if (!sceneQueue.isEmpty())
        {
            sceneQueue.dequeue();
            mathleQueue.dequeue();
        }
        score += 10;
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    }
}

void GameWidget::update()
{
    if (count >= 10) {
        count = 0;
        //Create a bomb
        // 0,0,0    x,0,x               0,0,x
        // Regular  Regular with shift  Upward arc
        int x = rand() % ui->graphicsView->contentsRect().width();
        mathleQueue.enqueue(new Mathle(x, 0, x+2));
        sceneQueue.enqueue(scene->addRect(mathleQueue.last()->posx, mathleQueue.last()->posy, 10, 10,QPen(Qt::red), QBrush(Qt::SolidPattern)));
    }
    else count++;
    int highestMathley = 0;
    //TODO: use iterator instead of for-loop
    for(int i=0; i<sceneQueue.length(); i++){
        if(sceneQueue[i]->pos().y()>highestMathley)
            highestMathley = mathleQueue[i]->posy;
    }
    // If a mathle has NOT hit the ground.
    if(highestMathley < ui->graphicsView->contentsRect().height()-10)
    {
        qDebug() << "fuf me";
        //double oldy = mathle1->posy;
        // Don't ask why, but for some reason posx and posy have to be assigned here.
        // y = (x-offSet)^2 / slowDown;
        // THEY ARE PUT IN AT THE TOP FIRST
        // If offset and x > 250, send it left
        for (size_t i = 0; i < sceneQueue.size(); i++) {
            mathleQueue[i]->posy = pow(mathleQueue[i]->posx - mathleQueue[i]->posxStart, 2)/gravity;
            sceneQueue[i]->setPos(mathleQueue[i]->posx, mathleQueue[i]->posy);
        }

//        qDebug() << mathle1->posx << mathle1->posy << mathle1->posy-oldy;
//        qDebug() << mathle2->posx << mathle2->posy << mathle2->posxStart;
//        qDebug() << mathle3->posx << mathle3->posy;
//        qDebug() << mathle4->posx << mathle4->posy;

    }
    // Mathle hit the ground
    else
    {
        qDebug() << "OVER";
/*
        //scene->addRect(0,0, 10, 10,QPen(), QBrush(Qt::SolidPattern));
        QGraphicsPixmapItem *q=new QGraphicsPixmapItem(QPixmap(":/new/prefix1/amissile.png"));

        q->setPos(mathleQueue.head()->pos().x(),mathleQueue.head()->pos().y()-500);
        mathleQueue.enqueue(q);
        q->setPos(0,0);
        //q->update();
        qDebug() << mathleQueue.size();

        QPixmap px(":/new/prefix1/amissile.png");
        QGraphicsPixmapItem *q1=new QGraphicsPixmapItem(px);

        mathleQueue.enqueue(q1);
        q1->setPos(mathleQueue.head()->pos().x(),mathleQueue.head()->pos().y()+650);

        QLabel *myLabel = new QLabel(this); // sets parent of label to main window
        myLabel->setPixmap(QPixmap(":/new/prefix1/anexplosion.png"));
        myLabel->move(mathleQueue.head()->pos().x(),mathleQueue.head()->pos().y()-100);
        myLabel->show();

        // create a timer to delete the label after a time
        QTimer* pShowTimer = new QTimer;
        pShowTimer->setSingleShot(true);

        connect(pShowTimer, &QTimer::timeout, [=](){
            delete myLabel;
        });

        pShowTimer->start(1000 * 1); // 1 second


        scene->removeItem(mathleQueue.head());
        qDebug() << mathleQueue.size();
*/
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
            //timer->stop();
            if (!sceneQueue.isEmpty())
            {
                delete(sceneQueue.dequeue());
                delete(mathleQueue.dequeue());
            }
            score += 10;
            ui->score->setText(QString::number(score));
            ui->answerBox->setText("");
            ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
        }
    }

