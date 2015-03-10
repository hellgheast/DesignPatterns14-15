#ifndef SHAPE_H
#define SHAPE_H

#include "Drawing.h"
#include <iostream>

using namespace std;

class Shape
{
    public:
        Shape(Drawing);
        virtual ~Shape();
        virtual void draw() = 0; //méthode virtuelle pure
    protected:
        Drawing apiDrawing;
    private:
};

#endif // SHAPE_H
