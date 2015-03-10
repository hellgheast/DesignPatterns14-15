#ifndef HEXAGONV1_H
#define HEXAGONV1_H
#include "Hexagon.h"

class HexagonV1 : public Hexagon
{
public:
    HexagonV1() {};
    virtual ~HexagonV1() {};
protected:
    void drawLine()
    {
        cout<<"HexagonV1 use drawLineV1()"<<endl;
    };
};

#endif // HEXAGONV1_H
