#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle() {};
    virtual ~Rectangle() {};
    void draw()
    {
        drawLine();
        drawLine();
        drawLine();
        drawLine();
    };
protected:
    virtual void drawLine()=0;
};

#endif // RECTANGLE_H
