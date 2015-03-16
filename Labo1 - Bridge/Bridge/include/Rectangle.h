#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(Drawing* _apiDrawing);
        ~Rectangle();
        void draw();
    protected:
    private:
};

#endif // RECTANGLE_H
