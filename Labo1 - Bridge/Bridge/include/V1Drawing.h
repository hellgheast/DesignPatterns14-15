#ifndef V1DRAWING_H
#define V1DRAWING_H
#include "Drawing.h"
#include <iostream>

using namespace std;

class V1Drawing : public Drawing
{
    public:
        V1Drawing();
        ~V1Drawing();

        void drawRectangle();
        void drawCircle();
        void drawHexagon();
    protected:
    private:
        void drawLineV1(int side);
        void drawPointV1();

};

#endif // V1DRAWING_H
