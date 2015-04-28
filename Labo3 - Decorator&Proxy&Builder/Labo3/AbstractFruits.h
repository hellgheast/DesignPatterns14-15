#ifndef ABSTRACTFRUITS_H
#define ABSTRACTFRUITS_H


class AbstractFruits
{
    public:
        AbstractFruits();
        virtual ~AbstractFruits();
        virtual AfficherFruits() = 0;
        virtual AvecOuSansPepin() = 0;
    protected:
    private:
};

#endif // ABSTRACTFRUITS_H
