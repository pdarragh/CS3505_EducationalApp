#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "equationgenerator.h"
#include "mathle.h"
#include "sstream"
#include <QGraphicsRectItem>
#include <QDebug>
#include <cmath>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    score(100)
{
    ui->setupUi(this);\
    gravity = 10; //Higher number = slower fall, cannot equal 0
    missed = 0;

    std::stringstream ss;
    ss << 1;
    QString some_level = QString::fromStdString(ss.str());
    QString str = "Level " + some_level;
    ui->level_label->setText(str);

    //equations = new EquationGenerator;
    //ui->equation->setText(equations->generateEquations(EquationGenerator::Addition));
    engine = new GameEngine();
    checkLevelAndSetEquation();

    //create the graphcis scene for the graphics view
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, getEditorCanvasSize(), getEditorCanvasSize());

    //connect(ui->answerButton, SIGNAL(clicked()), this, SLOT(on_answerButton_clicked()));
    //connect(this->ui->save_button, SIGNAL(clicked()), parentWidget(), SLOT(saveStudentGameResults(int, int, int)));
    connect(this->ui->save_button, SIGNAL(clicked()), this, SLOT(saveClicked()));

    // Hide explosion and show score
    this->ui->explosion->hide();
    ui->score->setText(QString::number(score));
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::startGame()
{
    score = 100;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(60);

    restartTimer = new QTimer(this);
    connect(restartTimer, SIGNAL(timeout()), this, SLOT(restart()));

    //Create a bomb
    mathle = new Mathle;
    mathle->makeMathle(0, 0, 0);
    scene->addRect(mathle->posx, mathle->posy, 10, 10,QPen(), QBrush(Qt::SolidPattern));

     checkLevelAndSetEquation();

    GameWidget::update();
}

void GameWidget::restart()
{
    restartTimer->stop();
    startGame();
}

void GameWidget::update()
{

    if(scene->items().first()->pos().y() < ui->graphicsView->contentsRect().height())
    {

        ui->explosion->hide();
        double oldy = mathle->posy;
        // Don't ask why, but for some reason posx and posy have to be assigned here.
        // y = (x-offSet)^2 / slowDown;
        scene->items().first()->setPos(mathle->posx++, (mathle->posy = pow(mathle->posx-mathle->posxStart, 2)/gravity));

        //qDebug() << mathle->posx << " " << mathle->posy << mathle->posy-oldy;
    }
    else
    {

        //stop timer
        //restart
        //new equation
        timer->stop();
        qDebug() << "OVER";

        ui->explosion->move(mathle->posx,mathle->posy - 200);
        ui->explosion->show();
        delete scene->items().first();

        restartTimer->start(300);

        // Subtract points from score
        score -= 10;
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        missed += 1;
    }
if(missed == 3)
{
    timer->stop();
    // Game won message
    QString str = "Game O!";
    ui->level_label->setText(str);
}
    if (score % 80 == 0)
    {
        timer->stop();
        if (current_level != 4)
        {

             delete scene->items().first();
            current_level += 1;
            setLevel(current_level);
            qDebug() << "WE'RE HITTING THAT";

            // Level display at top of screen
            std::stringstream ss;
            ss << current_level;
            QString some_level = QString::fromStdString(ss.str());
            QString str = "Level " + some_level;
            ui->level_label->setText(str);
            
            // SAVE LEVEL
    
            restart();
        }
        else
        {
            timer->stop();
            // Game won message
            QString str = "Game Won!";
            ui->level_label->setText(str);
            
            // saves game progress
        }
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
        qDebug() << "ANSWER = " + QString::fromStdString(engine->returnAnswer());

        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::red);
        ui->answerBox->setPalette(pal);
        ui->answerBox->setText("");

        // Attempting to get rid of
         timer->stop();
        delete scene->items().first();
        mathle = new Mathle;
        mathle->makeMathle(0, 0, 0);
        scene->addRect(mathle->posx, mathle->posy, 10, 10,QPen(), QBrush(Qt::SolidPattern));
        timer->start(100);
        score -= 10;
        std::stringstream ss;
        ss << score;
        this->ui->score->setText(QString::fromStdString(ss.str()));
        missed += 1;
    }
    else
    {
        QPalette pal = ui->answerBox->palette();
        pal.setColor(ui->answerBox->backgroundRole(), Qt::green);
        ui->answerBox->setPalette(pal);
        timer->stop();
        delete scene->items().first();
        ui->score->setText(QString::number(score));
        ui->answerBox->setText("");
        ui->equation->setText(engine->getEquation());
        mathle = new Mathle;
        mathle->makeMathle(0, 0, 0);
        scene->addRect(mathle->posx, mathle->posy, 10, 10,QPen(), QBrush(Qt::SolidPattern));
        timer->start(100);
        score += 10;
        std::stringstream ss;
        ss << score;
        this->ui->score->setText(QString::fromStdString(ss.str()));
    }
}

void GameWidget::setUsername(QString user)
{
    username = user;
}

void GameWidget::saveClicked()
{
    socket.connect();
    socket.recordStudentResult(username, current_level, score, missed);
    socket.disconnect();
}
