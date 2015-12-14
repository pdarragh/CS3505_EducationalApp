#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "equationgenerator.h"
#include "qstring.h"

class GameEngine
{
public:
    enum Difficulty { Easy=0, Intermediate, Hard, Extreme };
    Difficulty currentDifficulty;
    GameEngine();
    GameEngine(Difficulty difficulty);
    EquationGenerator::EquationType getEquationType(Difficulty difficulty);
    QString getEquation();
    void increaseLevel(Difficulty difficulty);
    std::string returnAnswer();
private:
    EquationGenerator equation_generator;
    void initialize(Difficulty difficulty);
};

#endif
