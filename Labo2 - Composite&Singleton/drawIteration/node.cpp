#include "node.h"

Node::Node()
{
}


Node::Node(QLineF _segment, int _deepness, QGraphicsLineItem* _qgli)
{
    segment = _segment;
    deepness = _deepness;
    qgli = _qgli;
    hasLeafsChildren = true;
}

Node::Node(double _x1, double _y1, double _x2, double _y2, int _deepness, QGraphicsLineItem* _qgli)
{
    segment = QLineF(_x1,_y1,_x2,_y2);
    deepness = _deepness;
    qgli = _qgli;
    hasLeafsChildren = true;
}

void Node::add(Component *element)
{
    children.append(element);
}

QList<Component*> Node::iterer(bool preLeaves){

}
