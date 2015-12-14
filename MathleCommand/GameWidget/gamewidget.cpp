#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "equationgenerator.h"
#include "mathle.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include <cmath>
#include <QBitmap>
#include <QMutex>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    score(0)
{
    ui->setupUi(this);\
    gravity = 10; //Higher number = slower fall, cannot equal 0

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
    mathle = new Mathle;
    mathle->makeMathle(0, 0, 0);
    //scene->addRect(mathle->posx, mathle->posy, 10, 10,QPen(), QBrush(Qt::SolidPattern));
    scene->addPixmap(QPixmap(":/new/prefix1/amissile.png"));
    scene->items().first()->setPos(mathle->posx,mathle->posy);
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
        if (scene->items().size() > 0)
        {
            scene->removeItem(scene->items().first());
        }
        score += 10;
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    }
}

void GameWidget::update()
{
    if(scene->items().size() >0)
    {
        if(scene->items().first()->pos().y() < ui->graphicsView->contentsRect().height())
        {
            qDebug() << "fuf me";
            double oldy = mathle->posy;
            // Don't ask why, but for some reason posx and posy have to be assigned here.
            // y = (x-offSet)^2 / slowDown;
            scene->items().first()->setPos(mathle->posx++, (mathle->posy = pow(mathle->posx-mathle->posxStart, 2)/gravity));

            qDebug() << mathle->posx << " " << mathle->posy << mathle->posy-oldy;


        }
        else
        {
            qDebug() << "OVER";
            mathle->posx = 0;
            mathle->posy = 0;

            //scene->addRect(0,0, 10, 10,QPen(), QBrush(Qt::SolidPattern));
            QGraphicsPixmapItem *q=new QGraphicsPixmapItem(QPixmap(":/new/prefix1/amissile.png"));

            q->setPos(scene->items().first()->pos().x(),scene->items().first()->pos().y()-500);
            scene->addItem(q);
            q->setPos(0,0);
            //q->update();
            qDebug() << scene->items().size();

            QPixmap px(":/new/prefix1/amissile.png");
            QGraphicsPixmapItem *q1=new QGraphicsPixmapItem(px);

            scene->addItem(q1);
            q1->setPos(scene->items().first()->pos().x(),scene->items().first()->pos().y()+650);

            QLabel *myLabel = new QLabel(this); // sets parent of label to main window
            myLabel->setPixmap(QPixmap(":/new/prefix1/anexplosion.png"));
            myLabel->move(scene->items().first()->pos().x(),scene->items().first()->pos().y()-100);
            myLabel->show();

            // create a timer to delete the label after a time
            QTimer* pShowTimer = new QTimer;
            pShowTimer->setSingleShot(true);

            connect(pShowTimer, &QTimer::timeout, [=](){
                delete myLabel;
            });

            pShowTimer->start(1000 * 1); // 1 second


            scene->removeItem(scene->items().first());
            qDebug() << scene->items().size();

        }
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
        if (scene->items().size() > 0)
        {
            scene->removeItem(scene->items().first());
        }
        score += 10;
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    }
}

