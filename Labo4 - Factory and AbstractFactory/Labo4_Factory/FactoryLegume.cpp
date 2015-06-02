#include "FactoryLegume.h"
#include "FactoryLegumeCuisson.h"
#include "FactoryLegumePotage.h"
#include "FactoryLegumeSalade.h"
#include "FactoryLegumeVapeur.h"
FactoryLegume::FactoryLegume()
{
    //ctor
}

FactoryLegume::~FactoryLegume()
{
    //dtor
}

Legume* FactoryLegume::createLegume(int choice)
{
    if (choice == 1)
        return FactoryLegumeCuisson::createLegume();
    else if (choice == 2)
        return FactoryLegumePotage::createLegume();
    else if (choice == 3)
        return FactoryLegumeSalade::createLegume();
    else
        return FactoryLegumeVapeur::createLegume();
}
