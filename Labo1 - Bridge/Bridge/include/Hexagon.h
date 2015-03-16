#ifndef HEXAGON_H
#define HEXAGON_H

#include "Shape.h"

class Hexagon : public Shape
{
    public:
        Hexagon(Drawing* _apiDrawing);
        ~Hexagon();
        void draw();
    protected:
    private:
};

#endif // HEXAGON_H
