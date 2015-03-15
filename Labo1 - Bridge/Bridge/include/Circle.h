#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    public:
        Circle(Drawing* _apiDrawing);
        virtual ~Circle();
    protected:
        virtual void draw();
    private:
};

#endif // CIRCLE_H
