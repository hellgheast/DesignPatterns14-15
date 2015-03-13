#ifndef RECTANGLEV2_H
#define RECTANGLEV2_H
#include "Rectangle.h"

class RectangleV2 : public Rectangle
{
public:
    RectangleV2() {};
    virtual ~RectangleV2() {};
protected:
    void drawLine()
    {
        cout<<"RectangleV2 use drawLineV2()"<<endl;
    };
};

#endif // RECTANGLEV2_H
