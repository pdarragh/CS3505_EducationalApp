
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
    gravity = 10; //Higher number = slower fall, cannot equal 0

    //equations = new EquationGenerator;
    //ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    engine = new GameEngine();
    checkLevelAndSetEquation();

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
    scene->addRect(mathle->posx, mathle->posy, 10, 10,QPen(), QBrush(Qt::SolidPattern));
    GameWidget::update();
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_answerButton_clicked()
{
    if(ui->answerBox->text() != QString::fromStdString(engine->returnAnswer()))
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
        ui->equation->setText(engine->getEquation());
    }
}

void GameWidget::update()
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
    }


}

int GameWidget::getEditorCanvasSize()
{
    QRect rcontent = ui->graphicsView->contentsRect();
    return std::min(rcontent.width(), rcontent.height());
}

void GameWidget::setLevel(int number)
{
    current_level = number;
    checkLevelAndSetEquation();

}

void GameWidget::checkLevelAndSetEquation()
{
    std::stringstream ss;
    ss << current_level;
    qDebug() << "Current Level = " + QString::fromStdString(ss.str());
    switch(current_level)
    {
    case 1:
        engine = new GameEngine(GameEngine::Difficulty::Easy);
        break;
    case 2:
        engine = new GameEngine(GameEngine::Difficulty::Intermediate);
        break;
    case 3:
        engine = new GameEngine(GameEngine::Difficulty::Hard);
        break;
    };
    this->ui->equation->setText(engine->getEquation());
}

void GameWidget::on_answerBox_returnPressed()
{
    if(ui->answerBox->text() != QString::fromStdString(engine->returnAnswer()))
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
        ui->equation->setText(engine->getEquation());
    }
}
