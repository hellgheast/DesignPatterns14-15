#ifndef SEGMENT_H
#define SEGMENT_H

#include <QList>

class Segment
{
public:
    Segment(double _x1, double _y1, double _x2, double _y2);
    QList<Segment *> iterer();

    double getX1() const;
    void setX1(double value);

    double getY1() const;
    void setY1(double value);

    double getX2() const;
    void setX2(double value);

    double getY2() const;
    void setY2(double value);

private:
    double x1,y1,x2,y2;
};

#endif // SEGMENT_H
