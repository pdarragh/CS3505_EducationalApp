#include "mathle.h"
#include <qglobal.h>
#include <QDebug>

Mathle::Mathle()
{

}

void Mathle::makeMathle(int posx, int posy, int posxStart)
{
    this->posx = posx;
    this->posy = posy;
    this->posxStart = posxStart;
}
