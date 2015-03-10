#ifndef HEXAGON_H
#define HEXAGON_H

#include "Shape.h"

class Hexagon : virtual public Shape
{
    public:
        Hexagon(Drawing _apiDrawing);
        virtual ~Hexagon();
    protected:
        virtual void draw();
    private:
};

#endif // HEXAGON_H
