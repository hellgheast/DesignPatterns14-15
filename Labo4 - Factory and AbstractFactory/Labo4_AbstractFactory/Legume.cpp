#include "Legume.h"
#include "LegumeCuisson.h"
#include "LegumePotage.h"
#include "LegumeSalade.h"
#include "LegumeVapeur.h"

Legume::Legume()
{
    //ctor
}

Legume::~Legume()
{
    //dtor
}

Legume* Legume::createLegume(int choice)
{
    if (choice == 1)
        return new LegumeCuisson();
    else if (choice == 2)
        return new LegumePotage();
    else if (choice == 3)
        return new LegumeSalade();
    else
        return new LegumeVapeur();
}
