#ifndef LEAFSEGMENT_H
#define LEAFSEGMENT_H
#include "component.h"

class LeafSegment : public Component
{
public:
    LeafSegment();
    LeafSegment(QLineF _segment, int _deepness = 0, QGraphicsLineItem* = NULL);
    LeafSegment(double _x1, double _y1, double _x2, double _y2, int _deepness = 0, QGraphicsLineItem* = NULL);

    virtual QList<Component*> iterer(int deepnessAsked);
};

#endif // LEAFSEGMENT_H
