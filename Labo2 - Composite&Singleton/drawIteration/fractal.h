#ifndef FRACTAL_H
#define FRACTAL_H

#include "segment.h"
#include <QGraphicsScene>
#include <QtWidgets>
#include <QList>


class Fractal //: public QWidget
{


public:    
    enum ItemAttribut{ItemDepth,ItemIsLeaf};

    ~Fractal(){}

    static Fractal* getInstance();
    void static deleteAllInstance();

    void createFractalFromSegment(Segment segInitial, int deepness);
    void createFractal(Segment seg, int deepness);

    QGraphicsScene *getScene() const;
    void setScene(QGraphicsScene *value);

private:
    Fractal(){}
    static QList<Fractal*> listFractal;
    static const int N_MAX = 5;
    QGraphicsScene * scene;
};

#endif // FRACTAL_H
