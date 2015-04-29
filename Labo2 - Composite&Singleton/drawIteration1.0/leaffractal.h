#ifndef LEAFFRACTAL_H
#define LEAFFRACTAL_H

#include "abstractfractal.h"

class LeafFractal : public AbstractFractal
{
public:
    LeafFractal(QLineF _segment, int _deepness);
    ~LeafFractal();

    void draw(QGraphicsScene *&scene);
    void add(AbstractFractal *){}
    QList<QLineF> computeNextLines(){return QList<QLineF>();}

private:

};

#endif // LEAFFRACTAL_H
