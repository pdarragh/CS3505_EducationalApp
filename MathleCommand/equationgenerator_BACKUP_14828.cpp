#include "equationgenerator.h"
#include <qglobal.h>
#include <QDebug>
<<<<<<< .merge_file_DoMc1F
#include <QTime>
=======
>>>>>>> .merge_file_N7pUoF

EquationGenerator::EquationGenerator()
{

}

<<<<<<< .merge_file_DoMc1F
QString EquationGenerator::generateEquations(EquationType type)
{
    QString equation = "";

    //have to have this to be truly random
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    int lhs = (qrand() % 10);
    int rhs = (qrand() % 10);

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

=======
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
>>>>>>> .merge_file_N7pUoF
