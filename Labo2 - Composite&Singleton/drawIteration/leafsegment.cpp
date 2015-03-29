#include "leafsegment.h"

LeafSegment::LeafSegment()
{
}


LeafSegment::LeafSegment(QLineF _segment, int _deepness, QGraphicsLineItem* _qgli)
{
    segment = _segment;
    deepness = _deepness;
    qgli = _qgli;
}

LeafSegment::LeafSegment(double _x1, double _y1, double _x2, double _y2, int _deepness, QGraphicsLineItem* _qgli)
{
    segment = QLineF(_x1,_y1,_x2,_y2);
    deepness = _deepness;
    qgli = _qgli;
}

QList<Component*> LeafSegment::iterer(int deepnessAsked){}
