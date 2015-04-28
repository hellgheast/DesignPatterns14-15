#ifndef FRACTAL_H
#define FRACTAL_H

#include "segment.h"
#include "compositefractal.h"
#include "leaffractal.h"
#include <QGraphicsScene>
#include <QtWidgets>
#include <QList>


class Fractal
{


public:    
    enum ItemAttribut{ItemDepth,ItemIsLeaf};

    ~Fractal();

    static Fractal* getInstance(QLineF segment, int profondeur);
    void static deleteAllInstance();

    //DP composite
    //--------
    void drawFractal(QGraphicsScene *& scene);
    //--------

//    void createFractalFromSegment(Segment segInitial, int deepness);
//    void createFractal(Segment seg, int deepness);

//    QGraphicsScene *getScene() const;
//    void setScene(QGraphicsScene *value);

private:
    Fractal(QLineF segment, int profondeur);
    static QList<Fractal*> listFractal;
    static const int N_MAX = 5;
    QGraphicsScene * scene;



    //DP composite
    //--------
    AbstractFractal* myfractal;
    void createFractalFromLineF(QLineF segment, int profondeur);
    //--------

};

#endif // FRACTAL_H
