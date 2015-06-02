#ifndef FACTORYLEGUMEVAPEUR_H
#define FACTORYLEGUMEVAPEUR_H
#include "FactoryLegume.h"
#include "LegumeVapeur.h"

class FactoryLegumeVapeur: public FactoryLegume
{
public:
    FactoryLegumeVapeur();
    virtual ~FactoryLegumeVapeur();

    static Legume* createLegume();
protected:
private:
};

#endif // FACTORYLEGUMEVAPEUR_H
