#ifndef V2DRAWING_H
#define V2DRAWING_H
#include "Drawing.h"

class V2Drawing
{
    public:
        //constructor
        V2Drawing();
        //destructor
        virtual ~V2Drawing();

        void drawCirclev2();
        void drawRectangleV2();
        void drawHexagonV2();
    protected:
    private:
        void drawLineV2(int side);
        void drawPointV2();
};

#endif // V2DRAWING_H
