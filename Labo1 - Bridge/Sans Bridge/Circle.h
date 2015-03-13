#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
public:
    Circle() {};
    virtual ~Circle() {};
    void draw()
    {
        drawPoints();
    };
protected:
    virtual void drawPoints()=0;
};

#endif // CIRCLE_H
