#ifndef V1DRAWING_H
#define V1DRAWING_H
#include "Drawing.h"

class V1Drawing : public Drawing
{
    public:
        V1Drawing();
        virtual ~V1Drawing();

        void drawRectangleV1();
        void drawCircleV1();
        void drawHexagonV1();
    protected:
    private:
        void drawLineV1(int side);
        void drawPointV1();

};

#endif // V1DRAWING_H
