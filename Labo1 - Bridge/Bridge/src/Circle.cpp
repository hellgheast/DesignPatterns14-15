#include "Circle.h"

Circle::Circle(Drawing _apiDrawing) : Shape(_apiDrawing)
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw(){
    //apiDrawing.drawCircle();
    cout << "circle" << endl;
}
