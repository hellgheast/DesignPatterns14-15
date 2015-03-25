#ifndef SEGMENT_H
#define SEGMENT_H

#include <QList>
#include <QLineF>
#include <QColor>

class Segment : QLineF
{
public:
    Segment(double _x1, double _y1, double _x2, double _y2, int _deepness = 0);
    Segment(QLineF _segment, int _deepness = 0);
    QList<Segment> iterer();

    double getX1() const;

    double getY1() const;

    double getX2() const;

    double getY2() const;

    int getDeepness() const;

    QColor getColor() const;
    int getWidth() const;

private:
    QLineF segment;
    int deepness;
};

#endif // SEGMENT_H
