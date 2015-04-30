#ifndef COMPONENTFRACTAL_H
#define COMPONENTFRACTAL_H

#include "abstractfractal.h"
#include <QList>

class CompositeFractal : public AbstractFractal
{
public:
    CompositeFractal(QLineF _segment, int _deepness);
    ~CompositeFractal();

    void add(AbstractFractal *ele);
    QList<QLineF> computeNextLines();

    void draw(QGraphicsScene *&scene);


private:

    QList<AbstractFractal *> children;
};

#endif // COMPONENTFRACTAL_H
