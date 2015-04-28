#ifndef PANIERDEFRUITS_H
#define PANIERDEFRUITS_H


class PanierDeFruits : public AbstractFruits
{
    public:
        PanierDeFruits(list<Fruit>);
        virtual ~PanierDeFruits();
        virtual AfficherFruits();
    protected:
    private:
        list<AbstractFruits> Fruits;
};

#endif // PANIERDEFRUITS_H
