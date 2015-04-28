#ifndef SEGMENT_H
#define SEGMENT_H

#include <QList>
#include <QLineF>
#include <QColor>
#include <QGraphicsLineItem>

class Segment : QLineF
{
public:
    Segment();
    Segment(double _x1, double _y1, double _x2, double _y2, int _deepness = 0);
    Segment(QLineF _segment, int _deepness = 0);
    QList<Segment> iterer();

    double getX1() const;

    double getY1() const;

    double getX2() const;

    double getY2() const;

    QLineF getSegment() const;

    int getDeepness() const;

    QColor getColor() const;

private:
    QLineF segment;
    int deepness;
};

#endif // SEGMENT_H
