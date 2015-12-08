#include "gameengine.h"

#include <QTime>

GameEngine::GameEngine()
{
    initialize(Difficulty::Easy);
}

GameEngine::GameEngine(Diffculty difficulty)
{
    initialize(difficulty);
}

void
GameEngine::initialize(Difficulty difficulty)
{
    difficulty = difficulty;
    equation_generator = EquationGenerator();
}

EquationType
GameEngine::getEquationType()
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    switch (difficulty)
    {
        case Difficulty::Easy:
            return EquationType::Adition;
        case Difficulty:Intermdiate:
            int r = (qrand() % 2);
            return static_cast<EquationType>(r);
        case Difficulty::Hard:
            int r = (qrand() % 3);
            return static_cast<EquationType>(r);
        case Difficulty::Extreme:
            int r = (qrand() % 4);
            return static_cast<EquationType>(r);
    }

    int r = (qrand() % 4);
    return static_cast<EquationType>(r);
}

QString
GameEngine::getEquation()
{
    return equation_generator.generateEquations(getEquationType());
}

void
GameEngine::increaseLevel()
{
    switch(difficulty)
    {
        case Difficulty::Easy:
            difficulty = Difficulty::Intermdiate;
            break;
        case Difficulty::Intermediate:
            difficulty = Difficulty::Hard;
            break;
        case Difficulty::hard:
            difficulty = Difficulty::Extreme;
            break;
    }
}
