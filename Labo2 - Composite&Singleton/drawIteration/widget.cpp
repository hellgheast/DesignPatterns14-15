#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent), scaleFactor(1.0), zoomStep(1.5), editionMode(false)
{
    scene = new QGraphicsScene(this);
    setMatrix(QMatrix(0.1,0,0,-0.1,0,0));
    pen = new QPen(Qt::red);
    pen->setWidth(0);
    setScene(scene);
    setSceneRect(-13000,-10000,26000,20000);

    QBrush b(Qt::black);
    scene->setBackgroundBrush(b);

    switchToEditionOrDisplay = new QAction(tr("Switch &mode"),this);
    switchToEditionOrDisplay->setShortcut(tr("Ctrl+M"));
    connect(switchToEditionOrDisplay, SIGNAL(triggered()), this, SLOT(changeMode()));
    this->addAction(switchToEditionOrDisplay);



    limite = 7;

    Segment segInitial = Segment(4650, 200, -850, -1900);
    Segment segInitial2 = Segment(4650, 200, 8050, -1900);

    if( (fractal = Fractal::getInstance()) ){
        fractal->setScene(scene);
        fractal->createFractalFromSegment(segInitial,limite);
    }

    if( (fractal = Fractal::getInstance()) ){
        fractal->setScene(scene);
        fractal->createFractalFromSegment(segInitial2,limite);
    }

    this->setDragMode(QGraphicsView::ScrollHandDrag);
    this->setRenderHints(QPainter::Antialiasing);
}

Widget::~Widget()
{
    fractal->deleteAllInstance();
    delete(pen);
}

void Widget::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        if (editionMode){
            pen->setColor(Qt::white);
            startLogic = mapToScene(event->pos());
            tempLineEdition = scene->addLine(0,0,0,0,*pen);
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
        tempLineEdition->setLine(startLogic.x(),startLogic.y(), endLogic.x(), endLogic.y());
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
            Fractal* tempFractal;   //au cas ou Fractal::getInstance() retourne 0
            if( (tempFractal = Fractal::getInstance()) ){
                fractal = tempFractal;
                fractal->setScene(scene);
                Segment initialSeg = Segment(tempLineEdition->line());
                fractal->createFractalFromSegment(initialSeg,limite);
            }
            else{
                scene->removeItem(tempLineEdition);
            }
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


/**
 * @brief Widget::wheelEvent
 * @param a
 * Zoom in or out, depending on wheel direction
 */
void Widget::wheelEvent(QWheelEvent * a){


    if(a->delta()>0.0)
    {
        if( scaleFactor < 10000.0)
        {
            scaleFactor *= zoomStep;
            scale(zoomStep, zoomStep);
            emit(scaleFactorChanged(scaleFactor));
        }
        else
        {
            emit(zoomLimitReached(true));
        }
    }
    else if(a->delta() < 0.0)
    {
        if(scaleFactor >= 0.3)
        {
            scaleFactor /= zoomStep;
            scale(1/zoomStep, 1/zoomStep);
            emit(scaleFactorChanged(scaleFactor));
        }
        else
        {
            emit(zoomLimitReached(false));
        }
    }


    if(!editionMode){
        keepDetailLevel();
        uniformiser();
    }
}

/**
 * @brief Widget::restoreOriginalZoom
 * all is in the method's name
 */
void Widget::restoreOriginalZoom(){
    scale(1/scaleFactor,1/scaleFactor);
    emit(scaleFactorChanged(scaleFactor));
}


QAction *Widget::getSwitchToEditionOrDisplay() const
{
    return switchToEditionOrDisplay;
}


/**
 * @brief   Recalcule les lignes pour garder un certain niveau de détail
 *          qui dépend de l'attribut "limite"
 */
void Widget::keepDetailLevel()
{
    QRectF viewRect =  mapToScene(this->rect()).boundingRect();
    QList<QGraphicsItem *> visibleItems = scene->items(viewRect);

    if(!visibleItems.isEmpty())
    {
        double deepest = visibleItems.first()->data(Fractal::ItemDepth).toInt();
        double highest = visibleItems.last()->data(Fractal::ItemDepth).toInt();

        double difference = deepest-highest;

        if (difference < limite)
        {
            while(!visibleItems.isEmpty() && visibleItems.first()->data(Fractal::ItemDepth).toInt() == deepest )
            {
                visibleItems.first()->setData(Fractal::ItemIsLeaf, false);
                QGraphicsLineItem* lineItem = (QGraphicsLineItem*)visibleItems.takeFirst();
                fractal->createFractal(Segment(lineItem->line(),deepest),1);
            }
        }
    }
}

/**
 * @brief   Uniformise la profondeur de toute les lignes
 */
void Widget::uniformiser()
{
    QRectF viewRect =  mapToScene(this->rect()).boundingRect();
    QList<QGraphicsItem *> visibleItems = scene->items(viewRect);

    if(!visibleItems.isEmpty())
    {
        int deepest = visibleItems.first()->data(Fractal::ItemDepth).toInt();
        int highest = visibleItems.last()->data(Fractal::ItemDepth).toInt();
        int diff =  deepest - highest;

        //suppression d'éléments pour éviter la surcharge
        if(diff > limite)
        {
            while(!visibleItems.isEmpty() && deepest-highest > limite)
            {
                scene->removeItem(visibleItems.takeFirst());
                if(!visibleItems.isEmpty())
                    deepest = visibleItems.first()->data(Fractal::ItemDepth).toInt();
            }
            while(!visibleItems.isEmpty() && deepest-highest == limite)
            {
                visibleItems.takeFirst()->setData(Fractal::ItemIsLeaf, true);
                if(!visibleItems.isEmpty())
                    deepest = visibleItems.first()->data(Fractal::ItemDepth).toInt();
            }
        }

        //mise à niveau des items de profondeur inférieur à la profondeur max
        //et qui n'ont pas d'enfants
        int depth;
        foreach(QGraphicsItem *visItem, visibleItems)
        {
            depth = visItem->data(Fractal::ItemDepth).toInt();
            if(depth < deepest)
            {
                if(visItem->data(Fractal::ItemIsLeaf).toBool())
                {
                    visItem->setData(Fractal::ItemIsLeaf, false);
                    QGraphicsLineItem* lineItem = (QGraphicsLineItem*)visItem;
                    fractal->createFractal(Segment(lineItem->line(),depth),deepest-depth);
                }
            }
        }
    }
}

/**
 * @brief   Alterne entre le mode Edition et le mode Display selon le mode actuel
 *          définit pas editionMode (true = mode Edition
 */
void Widget::changeMode()
{
    if(editionMode) //on est actuellement en mode edition et on veut changer vers Display
    {
        this->setDragMode(QGraphicsView::ScrollHandDrag);
        emit(switchMode(false));
    }
    else            //on est actuellement en mode display et on veut changer vers Edition
    {
        Fractal::deleteAllInstance();
        scene->clear();
        update();
        repaint();
        this->setDragMode(QGraphicsView::NoDrag);
        setCursor(QCursor(Qt::CrossCursor));
        emit(switchMode(true));
    }

    editionMode = !editionMode;
}
