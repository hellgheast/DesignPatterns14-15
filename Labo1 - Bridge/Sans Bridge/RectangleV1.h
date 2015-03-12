#ifndef RECTANGLEV1_H
#define RECTANGLEV1_H
#include "Rectangle.h"

class RectangleV1 : public Rectangle
{
public:
    RectangleV1() {};
    virtual ~RectangleV1() {};
protected:
    void drawLine()
    {
        cout<<"RectangleV1 use drawLineV1()"<<endl;
    };
};

#endif // RECTANGLEV1_H
