#include "fractal.h"
#include <QPen>
#include <QDebug>




QList<Fractal*> Fractal::listFractal = QList<Fractal*>();

QGraphicsScene *Fractal::getScene() const
{
    return scene;
}

void Fractal::setScene(QGraphicsScene *value)
{
    scene = value;
}

Fractal* Fractal::getInstance()
{
    if(listFractal.length() < N_MAX )
    {
        listFractal.append(new Fractal());
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
 * @brief Fractal::createFractalFromSegment
 * @param segInitial
 * @param deepness
 * création du 1er segment (segInitial) puis  creation de la suite du fractal avec la méthode Fractal::createFractal
 */
void Fractal::createFractalFromSegment(Segment segInitial, int deepness)
{
    QPen pen = QPen(segInitial.getColor());
    pen.setWidth(0);
    QGraphicsLineItem* segInitialLineItem = new QGraphicsLineItem(segInitial.getSegment());
    segInitialLineItem->setPen(pen);
    scene->addItem(segInitialLineItem);

    createFractal(segInitial, deepness);
}

/**
 * @brief Fractal::createFractal
 * @param firstRacine
 * @param profondeur
 * construction en largeur du fractal en utilisant une queue
 * Inspiré de l'algorithme suivant : http://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur
 */
void Fractal::createFractal(Segment firstRacine, int profondeur)
{
    //compteur du nombre d'itérations
    int compteur = 0;
    for(int i = 1; i <= profondeur; i++){
        compteur +=  qPow(3,i);
    }

    //initialisations des variables
    int profTotale = profondeur+firstRacine.getDeepness();
    QQueue<Segment> file;
    QList<Segment> listFils;
    listFils = firstRacine.iterer();
    foreach (Segment fils , listFils){
        file.enqueue(fils);
    }

    QGraphicsLineItem* qgliPere;
    Segment pere;
    QPen pen;


    while(compteur != 0){
        pere = file.dequeue();
        qgliPere = new QGraphicsLineItem(pere.getSegment());



        //data du lineItem
        qgliPere->setData(ItemDepth, pere.getDeepness());
        if(profTotale == pere.getDeepness()){
            qgliPere->setData(ItemIsLeaf, true);
        }
        else{
            qgliPere->setData(ItemIsLeaf, false);
        }

        //couleur
        pen = QPen(pere.getColor());
        pen.setWidth(0);
        qgliPere->setPen(pen);

        //ajout à la scène
        scene->addItem(qgliPere);

        //itération et ajout à la queue
        listFils = pere.iterer();
        foreach (Segment fils , listFils){
            file.enqueue(fils);
        }

        --compteur;
    }
}
