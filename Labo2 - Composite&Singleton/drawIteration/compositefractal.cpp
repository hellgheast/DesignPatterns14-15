#include "compositefractal.h"
#include <QGraphicsScene>

CompositeFractal::CompositeFractal(QLineF _segment, int _deepness): AbstractFractal(_segment, _deepness)
{
}

CompositeFractal::~CompositeFractal()
{
    foreach(AbstractFractal* abstractFractal , children)
    {
        delete(abstractFractal);
    }
}

void CompositeFractal::add(AbstractFractal *ele)
{
    children.append(ele);
}

QList<QLineF> CompositeFractal::computeNextLines()
{
    QList<QLineF> result;
    double lenX = (segment.x2() - segment.x1()) / 2;
    double lenY = (segment.y2() - segment.y1()) / 2;

    result.append( QLineF(segment.x2(), segment.y2(), segment.x2() + lenX, segment.y2() + lenY) ); // ligne en face
    result.append( QLineF(segment.x2(), segment.y2(), segment.x2() + lenY, segment.y2() - lenX) ); // ligne "droite"
    result.append( QLineF(segment.x2(), segment.y2(), segment.x2() - lenY, segment.y2() + lenX) ); // ligne "gauche"

    return result;
}

void CompositeFractal::draw(QGraphicsScene *& scene)
{
    scene->addLine(segment, pen);
    foreach(AbstractFractal* abstractFractal , children)
    {
        abstractFractal->draw(scene);
    }
}
