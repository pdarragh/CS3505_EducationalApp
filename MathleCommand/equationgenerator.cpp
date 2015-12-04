#include "equationgenerator.h"
#include <qglobal.h>
#include <QDebug>
#include <QTime>

EquationGenerator::EquationGenerator()
{

}

QString EquationGenerator::generateEquations(EquationType type)
{
        int lhs = (qrand() % 10);
        int rhs = (qrand() % 10);
        int answer = lhs + rhs;
        qDebug() << lhs << " + " << rhs << " =" << answer;
}

void EquationGenerator::generateSubtraction()
{
    QString equation = "";

    //have to have this to be truly random
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    int lhs = (qrand() % 10);
    int rhs = (qrand() % 10);
    int answer = lhs - rhs;

    switch (type) {
    case EquationType::Addition:
        equation.append(QString::number(lhs));
        equation.append("+");
        equation.append(QString::number(rhs));
        answer = lhs + rhs;
        break;
    case EquationType::Subtraction:
        equation.append(QString::number(lhs));
        equation.append("-");
        equation.append(QString::number(rhs));
         answer = lhs - rhs;
        break;
    case EquationType::Multiplication:
        equation.append(QString::number(lhs));
        equation.append("x");
        equation.append(QString::number(rhs));
         answer = lhs * rhs;
        break;
    case EquationType::Division:
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

