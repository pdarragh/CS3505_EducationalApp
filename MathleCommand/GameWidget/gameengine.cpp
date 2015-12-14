#include "gameengine.h"
#include "sstream"
#include <QTime>

GameEngine::GameEngine()
{
    initialize(Difficulty::Easy);
}

GameEngine::GameEngine(Difficulty difficulty)
{
    initialize(difficulty);
}

void
GameEngine::initialize(Difficulty difficulty)
{
    currentDifficulty = difficulty;
    equation_generator = EquationGenerator();
}

EquationGenerator::EquationType
GameEngine::getEquationType(Difficulty difficulty)
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    switch (difficulty)
    {
        case Easy:
            return EquationGenerator::EquationType::Addition;
        break;
        case Intermediate:
            return EquationGenerator::EquationType::Subtraction;
        case Hard:
            return EquationGenerator::EquationType::Multiplication;
        case Extreme:
            return EquationGenerator::EquationType::Division;
    }
}

QString
GameEngine::getEquation()
{
    return equation_generator.generateEquations(getEquationType(currentDifficulty));
}

void
GameEngine::increaseLevel(Difficulty difficulty)
{
    switch(difficulty)
    {
        case Easy:
            currentDifficulty = Difficulty::Intermediate;
            break;
        case Intermediate:
            currentDifficulty = Difficulty::Hard;
            break;
        case Hard:
            currentDifficulty = Difficulty::Extreme;
            break;
    }
}

std::string
GameEngine::returnAnswer()
{
    std::stringstream ss;
    ss << equation_generator.answer;
    return ss.str();
}
