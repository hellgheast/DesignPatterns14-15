#ifndef FRACTAL_H
#define FRACTAL_H

#include <QList>
#include <QLineF>
#include <QColor>
#include <QGraphicsLineItem>

class Component
{
public:
    Component();

    virtual QList<Component*> iterer(bool deepnessAsked) = 0;

    double getX1() const;

    double getY1() const;

    double getX2() const;

    double getY2() const;

    QLineF getSegment() const;

    int getDeepness() const;

    QColor getColor() const;


    QLineF segment;
    int deepness;
    QGraphicsLineItem* qgli;

};

#endif // FRACTAL_H
