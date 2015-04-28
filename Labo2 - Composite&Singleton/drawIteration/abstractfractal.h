#ifndef ABSTRACTFRACTAL_H
#define ABSTRACTFRACTAL_H

class QGraphicsScene;
#include <QLineF>
#include <QPen>

class AbstractFractal
{
public:
    AbstractFractal(QLineF _segment, int _deepness);
    virtual ~AbstractFractal();

    void virtual draw(QGraphicsScene *& scene) = 0;
    void virtual add(AbstractFractal *ele) = 0;
    QList<QLineF> virtual computeNextLines() = 0;

    int getDeepness() const;

protected:
    QLineF segment;
    int deepness;
    QPen pen;

};

#endif // ABSTRACTFRACTAL_H
