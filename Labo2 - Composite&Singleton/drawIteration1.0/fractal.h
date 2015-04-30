#ifndef FRACTAL_H
#define FRACTAL_H

#include "compositefractal.h"
#include "leaffractal.h"
#include <QGraphicsScene>
#include <QQueue>
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


private:
    Fractal(QLineF segment, int profondeur);
    static QList<Fractal*> listFractal;
    static const int N_MAX = 3;
    QGraphicsScene * scene;



    //DP composite
    //--------
    AbstractFractal* myfractal;
    void createFractalFromLineF(QLineF segment, int profondeur);
    //--------

};

#endif // FRACTAL_H
