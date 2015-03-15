#include "Rectangle.h"

Rectangle::Rectangle(Drawing* _apiDrawing) : Shape(_apiDrawing)
{
    //ctor
}

Rectangle::~Rectangle()
{
    //dtor
}

void Rectangle::draw(){
    apiDrawing->drawRectangle();
}
