#include "equationgenerator.h"
#include <qglobal.h>
#include <QDebug>
#include <QTime>

EquationGenerator::EquationGenerator()
{

}

QString EquationGenerator::generateEquations(EquationType type)
{
    QString equation = "";

    //have to have this to be truly random
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    int lhs = (qrand() % 10);
    int rhs = (qrand() % 10);

    switch (type) {
    case Addition:
        equation.append(QString::number(lhs));
        equation.append("+");
        equation.append(QString::number(rhs));
        answer = lhs + rhs;
        break;
    case Subtraction:
        equation.append(QString::number(lhs));
        equation.append("-");
        equation.append(QString::number(rhs));
         answer = lhs - rhs;
        break;
    case Multiplication:
        equation.append(QString::number(lhs));
        equation.append("x");
        equation.append(QString::number(rhs));
         answer = lhs * rhs;
        break;
    case Division:
        equation.append(QString::number(lhs));
        equation.append("/");
        equation.append(QString::number(rhs));
         answer = lhs / rhs;
        break;
    default:
        break;
    }

        qDebug() << lhs << " + " << rhs << " =" << answer;

        return equation;
}
