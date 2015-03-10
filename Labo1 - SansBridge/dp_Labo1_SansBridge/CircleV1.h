#ifndef CIRCLEV1_H
#define CIRCLEV1_H
#include "Circle.h"

class CircleV1 : public Circle
{
public:
    CircleV1() {};
    virtual ~CircleV1() {};
protected:
    void drawPoints()
    {
        cout<<"CircleV1 use drawPointsV1()"<<endl;
    };
};

#endif // CIRCLEV1_H
