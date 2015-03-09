#ifndef CIRCLEV2_H
#define CIRCLEV2_H
#include "Circle.h"

class CircleV2 : public Circle
{
public:
    CircleV2() {};
    virtual ~CircleV2() {};
protected:
    void drawPoints()
    {
        cout<<"CircleV2 use drawPointsV2()"<<endl;
    };
};

#endif // CIRCLEV2_H
