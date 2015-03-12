#ifndef V1DRAWING_H
#define V1DRAWING_H
#include "Drawing.h"

class V1Drawing : public Drawing
{
    public:
        V1Drawing();
        virtual ~V1Drawing();

        void drawRectangle()=0;
        void drawCircle()=0;
        void drawHexagon()=0;

    protected:
    private:

};

#endif // V1DRAWING_H
