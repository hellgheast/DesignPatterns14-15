#include "Hexagon.h"

Hexagon::Hexagon(Drawing* _apiDrawing) : Shape(_apiDrawing)
{
    //ctor
}

Hexagon::~Hexagon()
{
    //dtor
}

void Hexagon::draw(){
    apiDrawing->drawHexagon();
}
