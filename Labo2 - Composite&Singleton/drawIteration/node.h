#ifndef NODE_H
#define NODE_H
#include "component.h"

class Node : public Component
{

public:
    Node();
    Node(QLineF _segment, int _deepness = 0, QGraphicsLineItem* = NULL);
    Node(double _x1, double _y1, double _x2, double _y2, int _deepness = 0, QGraphicsLineItem* = NULL);

    QList<Component*> iterer(bool deepnessAsked);

    void add(Component* element);

private:
    QList<Component*> children;
    bool hasLeafsChildren;
};

#endif // NODE_H
