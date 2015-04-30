#include "fractal.h"
#include <QPen>
#include <QtMath>

QList<Fractal*> Fractal::listFractal = QList<Fractal*>();

Fractal::Fractal(QLineF segment, int profondeur)
{
    createFractalFromLineF(segment, profondeur);
}

Fractal::~Fractal()
{
    delete myfractal;
}

Fractal* Fractal::getInstance(QLineF segment, int profondeur)
{
    if(listFractal.length() < N_MAX )
    {
        listFractal.append(new Fractal(segment,profondeur));
        return listFractal.last();
    }
    else
        return 0;
}

void Fractal::deleteAllInstance()
{
    while(!listFractal.isEmpty()){
        delete(listFractal.takeLast());
    }
}

/**
 * @brief Fractal::createFractalFromLineF
 * @param segment
 * @param profondeur (minimum 1)
 * construction en largeur du fractal en utilisant une queue
 * Inspiré de l'algorithme suivant : http://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur
 */
void Fractal::createFractalFromLineF(QLineF segment, int profondeur)
{
    myfractal = new CompositeFractal(segment,0);

    //compteur du nombre d'itérations
    int compteur = 0;
    for(int i = 1; i <= profondeur; i++){
        compteur +=  qPow(3,i);
    }

    //initialisations des variables
    AbstractFractal* pere = myfractal;
    AbstractFractal* child;
    QQueue<AbstractFractal*> fileNodes;
    fileNodes.enqueue(pere);

    while(compteur != 0)
    {
        pere = fileNodes.dequeue();

        //itération et ajout à la queue
        foreach (QLineF childLine , pere->computeNextLines())
        {
            if(profondeur == pere->getDeepness()+1)
            {
                 child = new LeafFractal(childLine,pere->getDeepness()+1);
            }
            else
            {
                 child = new CompositeFractal(childLine,pere->getDeepness()+1);
            }
            pere->add(child);
            fileNodes.enqueue(child);
        }

        --compteur;
    }
}

void Fractal::drawFractal(QGraphicsScene *&scene)
{
    myfractal->draw(scene);
}
