#include "leaffractal.h"
#include <QGraphicsScene>
#include <QDebug>

LeafFractal::LeafFractal(QLineF _segment, int _deepness): AbstractFractal(_segment, _deepness)
{

}

LeafFractal::~LeafFractal()
{
}

void LeafFractal::draw(QGraphicsScene *&scene)
{
    scene->addLine(segment, pen);
}


