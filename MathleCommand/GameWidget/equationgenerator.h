#ifndef EQUATIONGENERATOR_H
#define EQUATIONGENERATOR_H
#include "qstring.h"


class EquationGenerator
{
public:
    enum EquationType { Addition=0, Subtraction, Multiplication, Division };
    EquationGenerator();
    int answer;
    QString generateEquations(EquationType type);

};

#endif // EQUATIONGENERATOR_H
