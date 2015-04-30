/*
	Design Patterns
	Labo3 : Panier de fruits avec State, Composite, Decorator
	Authors :
        - Karim Luy
        - Nicolas Gonin
        - Mathieu Bandelier
	Equipe1
************************************************************************
*/
#ifndef FRUIT_H
#define FRUIT_H


class Fruit
{
    public:
        Fruit() {}
        virtual ~Fruit() {}
        virtual bool hasPip() const = 0;
        virtual void showFruit() const = 0;
    protected:
        void showPip() const;
    private:
};

#endif // FRUIT_H
