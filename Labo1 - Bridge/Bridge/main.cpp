#include <iostream>

#include "circle.h"
#include "rectangle.h"
#include "hexagon.h"


using namespace std;

int main()
{
    Drawing drawing;
    Shape* circle = new Circle(drawing);
    Shape* rect = new Rectangle(drawing);
    Shape* hexagon = new Hexagon(drawing);

    circle->draw();
    rect->draw();
    hexagon->draw();

    return 0;
}
