#include "Hexagon.h"

Hexagon::Hexagon(Drawing _apiDrawing) : Shape(_apiDrawing)
{
    //ctor
}

Hexagon::~Hexagon()
{
    //dtor
}

void Hexagon::draw(){
    cout << "hexagon" << endl;
}
