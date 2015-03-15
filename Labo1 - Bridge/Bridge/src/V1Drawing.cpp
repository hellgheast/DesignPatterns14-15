#include "V1Drawing.h"

V1Drawing::V1Drawing()
{
    //ctor
}

V1Drawing::~V1Drawing()
{
    //dtor
}

void V1Drawing::drawCircleV1()
{
    drawPointV1();
}
void V1Drawing::drawRectangleV1()
{
    drawLineV1(1);
    drawLineV1(2);
    drawLineV1(3);
    drawLineV1(4);

}
void V1Drawing::drawHexagonV1()
{
    drawLineV1(1);
    drawLineV1(2);
    drawLineV1(3);
    drawLineV1(4);
    drawLineV1(5);
    drawLineV1(6);
}

void V1Drawing::drawPointV1()
{
    cout << "Drawing circle's points using API1." <<endl;
}

void V1Drawing::drawLineV1(int side)
{
    cout << "Drawing line " << side <<" using API1." << endl;
}
