#include "segment.h"

Segment::Segment(double _x1, double _y1, double _x2, double _y2): x1(_x1), y1(_y1), x2(_x2), y2(_y2)
{

}

QList<Segment*> Segment::iterer(){
    QList<Segment*> result;
    double lenX = (this->x2 - this->x1) / 2;
    double lenY = (this->y2 - this->y1) / 2;;
    //ligne1
    result.append(new Segment(this->x2, this->y2, this->x2 + lenX, this->y2 + lenY) );

    //double a = -(this->y2 - this->y1)/(this->x2 - this->x1); //équation: y = ax+b
    //double b = this->y2 - a*this->x2;

    //ligne2 "droite"
    result.append(new Segment(this->x2, this->y2, this->x2 + lenY, this->y2 - lenX));

    //ligne3 "gauche"
    result.append(new Segment(this->x2, this->y2, this->x2 - lenY, this->y2 + lenX));

    return result;
}


double Segment::getX1() const
{
    return x1;
}

void Segment::setX1(double value)
{
    x1 = value;
}
double Segment::getY1() const
{
    return y1;
}

void Segment::setY1(double value)
{
    y1 = value;
}

double Segment::getX2() const
{
    return x2;
}

void Segment::setX2(double value)
{
    x2 = value;
}

double Segment::getY2() const
{
    return y2;
}

void Segment::setY2(double value)
{
    y2 = value;
}
