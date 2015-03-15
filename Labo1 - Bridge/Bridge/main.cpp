#include <iostream>
#include "Shape.h"
#include "V1Drawing.h"
#include "V2Drawing.h"

#include "circle.h"
#include "rectangle.h"
#include "hexagon.h"


using namespace std;

int main()
{
    V1Drawing* drawing1 = new V1Drawing();
    V2Drawing* drawing2 = new V2Drawing();

    Shape* circle1 = new Circle(drawing1);
    Shape* circle2 = new Circle(drawing2);
    Shape* rect1 = new Rectangle(drawing1);
    Shape* rect2 = new Rectangle(drawing2);
    Shape* hexagon1 = new Hexagon(drawing1);
    Shape* hexagon2 = new Hexagon(drawing2);



    circle1->draw();
    rect1->draw();
    hexagon1->draw();

    cout << endl;

    circle2->draw();
    rect2->draw();
    hexagon2->draw();

    return 0;
}
