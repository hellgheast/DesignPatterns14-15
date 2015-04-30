#ifndef ABSTRACTFRUITS_H
#define ABSTRACTFRUITS_H


class AbstractFruits
{
    public:
        AbstractFruits();
        virtual ~AbstractFruits();
        virtual void AfficherFruits() = 0;
        virtual bool AvecOuSansPepin() = 0;
    protected:
    private:
};

#endif // ABSTRACTFRUITS_H
