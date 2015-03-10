#ifndef HEXAGONV2_H
#define HEXAGONV2_H
#include "Hexagon.h"

class HexagonV2 : public Hexagon
{
public:
    HexagonV2() {};
    virtual ~HexagonV2() {};
protected:
    void drawLine()
    {
        cout<<"HexagonV2 use drawLineV2()"<<endl;
    };
};

#endif // HEXAGONV2_H
