#ifndef FRUIT_H
#define FRUIT_H


class Fruit : public PanierDeFruits
{
    public:
        Fruit(string, bool);
        virtual ~Fruit();
        void AfficherFruit() {cout<<nomDuFruit;}
    protected:
    private:
        string nomDuFruit;
        bool pepin;
};

#endif // FRUIT_H
