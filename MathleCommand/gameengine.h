#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "equationgenerator.h"
#include "qstring.h"

class GameEngine
{
public:
    enum Difficulty { Easy=0, Intermediate, Hard, Extreme };
    GameEngine();
    GameEngine(Difficulty difficulty);
    QString getEquation();
    void increaseLevel();
private:
    EquationGenerator equation_generator;
    void initialize(Difficulty difficulty);
};

#endif
