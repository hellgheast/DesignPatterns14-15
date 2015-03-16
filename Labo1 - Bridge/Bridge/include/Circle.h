#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    public:
        Circle(Drawing* _apiDrawing);
        ~Circle();
        void draw();
    protected:
    private:
};

#endif // CIRCLE_H
