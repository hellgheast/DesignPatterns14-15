#include "V2Drawing.h"

V2Drawing::V2Drawing()
{
    //ctor
}

V2Drawing::~V2Drawing()
{
    //dtor
}

void V2Drawing::drawCircle()
{
    drawPointV2();
}
void V2Drawing::drawRectangle()
{
    cout << "Drawing rectangle using API2." << endl;
}
void V2Drawing::drawHexagon()
{
    cout << "Drawing hexagon using API2." << endl;
}

void V2Drawing::drawPointV2()
{
    cout << "Drawing circle's points using API2." << endl;
}

void V2Drawing::drawLineV2(int side)
{
    cout << "Drawing line " << side << " using API2." << endl;
}
