#ifndef V2DRAWING_H
#define V2DRAWING_H
#include "Drawing.h"
#include <iostream>

using namespace std;

class V2Drawing : public Drawing
{
    public:
        //constructor
        V2Drawing();
        //destructor
        virtual ~V2Drawing();

        void drawRectangle();
        void drawCircle();
        void drawHexagon();
    protected:
    private:
        void drawLineV2(int side);
        void drawPointV2();
};

#endif // V2DRAWING_H
