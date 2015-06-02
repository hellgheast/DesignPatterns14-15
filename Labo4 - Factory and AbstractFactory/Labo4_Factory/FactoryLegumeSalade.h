#ifndef FACTORYLEGUMESALADE_H
#define FACTORYLEGUMESALADE_H
#include "FactoryLegume.h"
#include "LegumeSalade.h"

class FactoryLegumeSalade: public FactoryLegume
{
public:
    FactoryLegumeSalade();
    virtual ~FactoryLegumeSalade();

    static Legume* createLegume();
protected:
private:
};

#endif // FACTORYLEGUMESALADE_H
