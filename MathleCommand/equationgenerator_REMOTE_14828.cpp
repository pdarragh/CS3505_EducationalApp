#include "equationgenerator.h"
#include <qglobal.h>
#include <QDebug>

EquationGenerator::EquationGenerator()
{

}

void EquationGenerator::generateAddition()
{
        int lhs = (qrand() % 10);
        int rhs = (qrand() % 10);
        int answer = lhs + rhs;
        qDebug() << lhs << " + " << rhs << " =" << answer;
}
void EquationGenerator::generateSubtraction()
{
    int lhs = (qrand() % 10);
    int rhs = (qrand() % 10);
    int answer = lhs - rhs;

   qDebug() << lhs << " + " << rhs << " =" << answer;

}
