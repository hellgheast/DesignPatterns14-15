#ifndef HEXAGON_H
#define HEXAGON_H
#include "Shape.h"

class Hexagon : public Shape
{
public:
    Hexagon() {};
    virtual ~Hexagon() {};
    void draw()
    {
        drawLine();
        drawLine();
        drawLine();
        drawLine();
        drawLine();
        drawLine();
    };
protected:
    virtual void drawLine()=0;
};

#endif // HEXAGON_H
