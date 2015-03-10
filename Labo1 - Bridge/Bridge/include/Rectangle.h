#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : virtual public Shape
{
    public:
        Rectangle(Drawing _apiDrawing);
        virtual ~Rectangle();
    protected:
        virtual void draw();
    private:
};

#endif // RECTANGLE_H
