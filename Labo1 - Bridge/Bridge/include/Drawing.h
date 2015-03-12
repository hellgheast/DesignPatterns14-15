#ifndef DRAWING_H
#define DRAWING_H


class Drawing
{
    public:
        //constructor
        Drawing();
        //destructor
        virtual ~Drawing();

    protected:

        //virtual methods
        virtual void drawRectangle()=0;
        virtual void drawCircle()=0;
        virtual void drawHexagon()=0;

    private:
};

#endif // DRAWING_H
