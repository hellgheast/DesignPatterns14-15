#include "component.h"

Component::Component()
{
}

//QList<Component*> Component::iterer(bool preLeaves){
    //QList<Segment> result;

//}


double Component::getX1() const
{
    return segment.x1();
}

double Component::getY1() const
{
    return segment.y1();
}

double Component::getX2() const
{
    return segment.x2();
}

double Component::getY2() const
{
    return segment.y2();
}

QLineF Component::getSegment() const
{
    return segment;
}

int Component::getDeepness() const
{
    return deepness;
}

QColor Component::getColor() const
{
    int r = qMax(255-deepness*20,0);
    int g = qMin(20*deepness,255);
    int b = 0;
    return QColor(r,g,b);
}
