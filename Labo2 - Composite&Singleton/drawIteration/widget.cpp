#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent), scaleFactor(1.0), editionMode(false)
{
    scene = new QGraphicsScene(this);
    setMatrix(QMatrix(0.1,0,0,-0.1,0,0));
    pen = new QPen(Qt::red);
    pen->setWidth(0);
    setScene(scene);
    setSceneRect(-13000,-10000,26000,20000);

    QBrush b(Qt::black);
    scene->setBackgroundBrush(b);

    switchToEditionOrDisplay = new QAction(this);
    switchToEditionOrDisplay->setShortcut(tr("Ctrl+M"));
    connect(switchToEditionOrDisplay, SIGNAL(triggered()), this, SLOT(changeMode()));
    this->addAction(switchToEditionOrDisplay);



//    LeafSegment* compInitial = new LeafSegment(4650, 200, -850, -1900, 0);
//    fractal2(6,compInitial);

    limite = 7;

    Segment segInitial = Segment(4650, 200, -850, -1900);
    createFractFromSegment(segInitial);

    Segment segInitial2 = Segment(4650, 200, 8050, -1900);
    createFractFromSegment(segInitial2);


    this->setDragMode(QGraphicsView::ScrollHandDrag);
    this->setRenderHints(QPainter::Antialiasing);
}

Widget::~Widget()
{

}

/**
 * @brief Widget::fractal
 * @param profondeur
 * @param firstRacine
 *
 * construction en largeur du fractal en utilisant une queue
 * Inspiré de l'algorithme suivant : http://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur
 */
void Widget::fractal(int profondeur, Segment firstRacine)
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
        pen->setColor(pere.getColor());
        qgliPere->setPen(*pen);

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

void Widget::createFractFromSegment(Segment segInitial)
{
    pen->setColor(segInitial.getColor());
    QGraphicsLineItem* segInitialLineItem = new QGraphicsLineItem(segInitial.getSegment());
    segInitialLineItem->setPen(*pen);
    scene->addItem(segInitialLineItem);
    segInitial.setOwnLineItemPtr(segInitialLineItem);

    fractal(limite,segInitial);
}

/**
 * @brief Widget::fractal2
 * @param profondeur ( > noeudRacine->getDeppness() )
 * @param noeudRacine
 */
void Widget::fractal2(int profondeur, LeafSegment *noeudRacine)
{
//    if(profondeur > noeudRacine->getDeepness() ){
//        int compteur = 0;
//        for(int i = noeudRacine->getDeepness()+1; i <= profondeur; i++){
//            compteur +=  qPow(3,i);
//        }

//        QQueue<Node*> file;
//        file.append(noeudRacine);
//        Node* racine;
//        QList<Node*> listFils;
//        QGraphicsLineItem* qgli;

//        while(compteur != 0){
//            racine = file.takeFirst();

//            qgli = new QGraphicsLineItem(racine->getSegment());

//            pen->setColor(racine->getColor());
//            qgli->setPen(*pen);

//            scene->addItem(qgli);

//            //scene->addLine(racine->getX1(), racine->getY1(), racine->getX2(), racine->getY2(),*pen);
//            //scene->addItem(MyLineItem(racine.getDeepness(),QGraphicsLineItem(racine.getX1(), racine.getY1(), racine.getX2(), racine.getY2())));

//            listFils = racine.iterer();
//            foreach (Segment fils , listFils)
//                file.append(fils);

//            --compteur;
//        }
//    }
//    else{
//        qDebug() << "rien à faire";
//    }

}


void Widget::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        if (editionMode){
            startLogic = mapToScene(event->pos());
            tempLineEdition = scene->addLine(0,0,0,0);
        }
    }
    else if( event->button() == Qt::MidButton){
        restoreOriginalZoom();
    }
    else if( event->button() == Qt::RightButton){

        this->setDragMode(QGraphicsView::NoDrag);

        QPixmap pix(":/resources/rotation.png");
        pix.setMask(QBitmap(":/resources/rotation.png"));
        setCursor(QCursor(pix));

    }
    QGraphicsView::mousePressEvent(event);

}

void Widget::mouseMoveEvent(QMouseEvent * event){
    if((event->buttons() == Qt::LeftButton && editionMode) ){
        endLogic = mapToScene(event->pos());
        scene->removeItem(tempLineEdition);
        pen->setColor(Qt::white);
        pen->setWidth(10/scaleFactor);
        tempLineEdition = scene->addLine(startLogic.x(),startLogic.y(), endLogic.x(), endLogic.y(), *pen);
    }
    else if(event->buttons()== Qt::RightButton){
         rotate(2);
    }
    QGraphicsView::mouseMoveEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton){
        if (editionMode){
            createdLines.append(tempLineEdition);
            pen->setWidth(0);
        }
        else{
            keepDetailLevel();
            uniformiser();
        }
    }
    if (event->button() == Qt::RightButton){
        if(editionMode){
            setCursor(QCursor(Qt::CrossCursor));
        }
        else{
            this->setDragMode(QGraphicsView::ScrollHandDrag);
        }
    }

    QGraphicsView::mouseReleaseEvent(event);

}



void Widget::wheelEvent(QWheelEvent * a){
    QMatrix*  transform = new QMatrix(this->matrix().m11()/scaleFactor,this->matrix().m12()/scaleFactor,this->matrix().m21()/scaleFactor,this->matrix().m22()/scaleFactor,0,0);
    if(a->delta()>0.0){
        if( scaleFactor < 10000.0){
            scaleFactor *= 1.5;
            emit(scaleFactorChanged(scaleFactor));
        }
        else{
            qDebug() << "max zoom reached";
        }
    }
    else if(scaleFactor >= 0.3){
        scaleFactor /= 1.5;
        emit(scaleFactorChanged(scaleFactor));
    }

    setMatrix(QMatrix(transform->m11()*scaleFactor,transform->m12()*scaleFactor, transform->m21()*scaleFactor, transform->m22()*scaleFactor,0,0));

    if(!editionMode){
        keepDetailLevel();
        uniformiser();
    }
}


void Widget::restoreOriginalZoom(){
    setMatrix(QMatrix(matrix().m11()/scaleFactor,matrix().m12()/scaleFactor,matrix().m21()/scaleFactor,matrix().m22()/scaleFactor,0,0) );
    scaleFactor = 1.0;
    emit(scaleFactorChanged(scaleFactor));
}


/**
 * @brief Widget::keepDetailLevel
 * Recalcule les lignes pour garder un certain niveau de détail
 * qui dépend de l'attribut "limite"
 */
void Widget::keepDetailLevel()
{
    QRectF viewRect =  mapToScene(this->rect()).boundingRect();
    QList<QGraphicsItem *> visibleItems = scene->items(viewRect);

    double deepest = visibleItems.first()->data(ItemDepth).toInt();
    double highest = visibleItems.last()->data(ItemDepth).toInt();

    double difference = deepest-highest;

    if (difference < limite){
        while( visibleItems.first()->data(ItemDepth).toInt() == deepest ){
            visibleItems.first()->setData(ItemIsLeaf, false);
            QGraphicsLineItem* lineItem = (QGraphicsLineItem*)visibleItems.takeFirst();
            fractal(1,Segment(lineItem->line(),deepest));
        }
    }
}

/**
 * @brief Widget::uniformise la profondeur de toute les lignes
 */
void Widget::uniformiser()
{
    QRectF viewRect =  mapToScene(this->rect()).boundingRect();
    QList<QGraphicsItem *> visibleItems = scene->items(viewRect);

    int deepest = visibleItems.first()->data(ItemDepth).toInt();
    int highest = visibleItems.last()->data(ItemDepth).toInt();
    int diff =  deepest - highest;

    //suppression d'éléments pour éviter la surcharge
    if(diff > limite){
        while(deepest-highest > limite){
            scene->removeItem(visibleItems.takeFirst());
            deepest = visibleItems.first()->data(ItemDepth).toInt();
        }
        while(deepest-highest == limite){
            visibleItems.takeFirst()->setData(ItemIsLeaf, true);
            deepest = visibleItems.first()->data(ItemDepth).toInt();
        }
    }

    //mise à niveau des items de profondeur inférieur à la profondeur max
    //et qui n'ont pas d'enfants
    int depth;
    foreach(QGraphicsItem *visItem, visibleItems){
        depth = visItem->data(ItemDepth).toInt();
        if(depth < deepest){
            if(visItem->data(ItemIsLeaf).toBool()){
                visItem->setData(ItemIsLeaf, false);
                QGraphicsLineItem* lineItem = (QGraphicsLineItem*)visItem;
                fractal(deepest-depth,Segment(lineItem->line(),depth));
            }
        }
    }
}

void Widget::changeMode()
{
    if(editionMode){
        foreach(QGraphicsLineItem* lineItem, createdLines){
            createFractFromSegment(Segment(lineItem->line()));
        }
        this->setDragMode(QGraphicsView::ScrollHandDrag);
    }
    else{
        scene->clear();
        createdLines.clear();
        this->setDragMode(QGraphicsView::NoDrag);
        setCursor(QCursor(Qt::CrossCursor));
    }

    editionMode = !editionMode;
}
