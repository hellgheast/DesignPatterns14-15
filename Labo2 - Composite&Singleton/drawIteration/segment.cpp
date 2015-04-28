#include "segment.h"

Segment::Segment()
{

}

Segment::Segment(double _x1, double _y1, double _x2, double _y2, int _deepness): deepness(_deepness)
{
    segment = QLineF(_x1,_y1,_x2,_y2);
}

Segment::Segment(QLineF _segment, int _deepness): segment(_segment), deepness(_deepness)
{

}

QList<Segment> Segment::iterer(){
    QList<Segment> result;
    double lenX = (segment.x2() - segment.x1()) / 2;
    double lenY = (segment.y2() - segment.y1()) / 2;

    //ligne1
    result.append( Segment(segment.x2(), segment.y2(), segment.x2() + lenX, segment.y2() + lenY, deepness+1) );

    //ligne2 "droite"
    result.append( Segment(segment.x2(), segment.y2(), segment.x2() + lenY, segment.y2() - lenX, deepness+1) );

    //ligne3 "gauche"
    result.append( Segment(segment.x2(), segment.y2(), segment.x2() - lenY, segment.y2() + lenX, deepness+1) );

    return result;
}


double Segment::getX1() const
{
    return segment.x1();
}

double Segment::getY1() const
{
    return segment.y1();
}

double Segment::getX2() const
{
    return segment.x2();
}

double Segment::getY2() const
{
    return segment.y2();
}

QLineF Segment::getSegment() const
{
    return segment;
}

int Segment::getDeepness() const
{
    return deepness;
}

QColor Segment::getColor() const
{
    double facteur = (deepness%20)/20.0;
    return QColor::fromHsvF(facteur,1,1);
}
