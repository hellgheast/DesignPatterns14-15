#include "widget.h"

Widget::Widget(int _deepness, QWidget *parent)
    : QGraphicsView(parent), scaleFactor(1.0), zoomStep(1.5), editionMode(false)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    setSceneRect(-13000,-10000,26000,20000);
    setMatrix(QMatrix(0.1,0,0,-0.1,0,0));

    QBrush b(Qt::black);
    scene->setBackgroundBrush(b);
    pen = new QPen(Qt::white);
    pen->setWidth(0);

    deepness = _deepness;

    QLineF segInitial = QLineF(4650, 200, -850, -1900);
    QLineF segInitial2 = QLineF(4650, 200, 8050, -1900);

    if( (fractal = Fractal::getInstance(segInitial,deepness)) ){
        fractal->drawFractal(scene);
        editionLines.append(segInitial);
    }

    if( (fractal = Fractal::getInstance(segInitial2,deepness)) ){
        fractal->drawFractal(scene);
        editionLines.append(segInitial2);
    }

    this->setDragMode(QGraphicsView::ScrollHandDrag);
}

Widget::~Widget()
{
    Fractal::deleteAllInstance();

    delete(pen);
}

void Widget::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        if (editionMode){
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
            scene->removeItem(tempLineEdition);


            if( (fractal = Fractal::getInstance(tempLineEdition->line(),deepness)) ){
                fractal->drawFractal(scene);
                editionLines.append(tempLineEdition->line());
            }
            delete(tempLineEdition);
        }
        else{
            //...
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
        if( scaleFactor < 150.0)
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
        //...
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


/**
 * @brief   Alterne entre le mode Edition et le mode Display selon le mode actuel
 *          définit pas editionMode (true = mode Edition)
 */
void Widget::changeMode()
{
    if(editionMode) //on est actuellement en mode EDITION et on veut changer vers EXPLORE
    {
        this->setDragMode(QGraphicsView::ScrollHandDrag);
        emit(switchMode(false));
    }
    else            //on est actuellement en mode EXPLORE et on veut changer vers EDITION
    {
        Fractal::deleteAllInstance();
        editionLines.clear();
        scene->clear();

        update();
        repaint();
        this->setDragMode(QGraphicsView::NoDrag);
        setCursor(QCursor(Qt::CrossCursor));
        emit(switchMode(true));
    }

    editionMode = !editionMode;
}

void Widget::redraw(int newDeepness)
{
    scene->clear();
    Fractal::deleteAllInstance();

    deepness = newDeepness;

    foreach(QLineF editionLine, editionLines)
    {
        if( (fractal = Fractal::getInstance(editionLine,deepness)) ){
            fractal->drawFractal(scene);
        }
    }
    update();
}
