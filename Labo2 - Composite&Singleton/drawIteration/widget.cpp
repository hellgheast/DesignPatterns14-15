#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent), scaleFactor(1.0), editionMode(false)
{
    scene = new QGraphicsScene(this);
    setMatrix(QMatrix(0.1,0,0,-0.1,0,0));
    pen = new QPen(Qt::red);
    pen->setWidth(0);


    //scene->addLine(0,0,0,150,QPen(Qt::green));
    //scene->addLine(0,0,150,0,QPen(Qt::red));
    //txt1 = new QGraphicsTextItem();
    //txt1->setMatrix(QMatrix(1,0.1,0,-1,0,this->fontMetrics().lineSpacing()*3 + 3));
    //scene->addItem(txt1);
    //texteUpdate();

    setScene(scene);
    setSceneRect(-13000,-10000,26000,20000);

    quitFullScreen = new QAction(this);
    quitFullScreen->setShortcut(Qt::Key_Escape);
    connect(quitFullScreen,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->addAction(quitFullScreen);

    switchToEditionOrDisplay = new QAction(this);
    switchToEditionOrDisplay->setShortcut(tr("Ctrl+M"));
    connect(switchToEditionOrDisplay, SIGNAL(triggered()), this, SLOT(changeMode()));
    this->addAction(switchToEditionOrDisplay);

    setWindowTitle("DP - EQUIPE I - LABO 2 / Fractal  (Ctrl+m to switch to edit mode)");


    Segment segInitial = Segment(4650, 200, -850, -1900, 1);
    Segment segInitial2 = Segment(4650, 200, 8050, -1900, 1);

    fractal(8,segInitial);
    fractal(8,segInitial2);


    this->setDragMode(QGraphicsView::ScrollHandDrag);
    this->setRenderHints(QPainter::SmoothPixmapTransform);

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
    int compteur = 0;
    for(int i = 0; i <= profondeur; i++){
        compteur +=  qPow(3,i);
    }


    QQueue<Segment> file;
    file.append(firstRacine);
    Segment racine = Segment(0,0,0,0);
    QList<Segment> listFils;

    while(compteur != 0){
        racine = file.takeFirst();
        pen->setColor(racine.getColor());
        scene->addLine(racine.getX1(), racine.getY1(), racine.getX2(), racine.getY2(),*pen);
        //scene->addItem(MyLineItem(racine.getDeepness(),QGraphicsLineItem(racine.getX1(), racine.getY1(), racine.getX2(), racine.getY2())));
        listFils = racine.iterer();
        foreach (Segment fils , listFils)
            file.append(fils);

        --compteur;
    }
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
        texteUpdate();
    }
    QGraphicsView::mousePressEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent * event){    
    if((event->buttons() == Qt::LeftButton && editionMode) ){
        endLogic = mapToScene(event->pos());
        scene->removeItem(tempLineEdition);
        tempLineEdition = scene->addLine(startLogic.x(),startLogic.y(), endLogic.x(), endLogic.y());
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
        }
        else{


            //recompute();
        }
    }
    QGraphicsView::mouseReleaseEvent(event);

}

void Widget::mouseDoubleClickEvent(QMouseEvent * event)
{
    if ( event->button() == Qt::LeftButton )
    {
        this->showFullScreen();
    }
    QGraphicsView::mouseDoubleClickEvent(event);
}

void Widget::wheelEvent(QWheelEvent * a){
    QMatrix*  transform = new QMatrix(this->matrix().m11()/scaleFactor,this->matrix().m12()/scaleFactor,this->matrix().m21()/scaleFactor,this->matrix().m22()/scaleFactor,0,0);
    if(a->delta()>0.0){
        if( scaleFactor < 300.0){
            scaleFactor *= 1.5;
            qDebug() << scaleFactor;
        }
        else{
            qDebug() << "max zoom reached";
        }
    }
    else if(scaleFactor >= 0.3){
        scaleFactor /= 1.5;
    }

    setMatrix(QMatrix(transform->m11()*scaleFactor,transform->m12()*scaleFactor, transform->m21()*scaleFactor, transform->m22()*scaleFactor,0,0));
    texteUpdate();

    if(!editionMode)
        recompute();
}

void Widget::texteUpdate(){
    QString lx = QString().number(endLogic.x(),'f',2);
    QString ly = QString().number(endLogic.y(),'f',2);
    //txt1->setPlainText(QString("Coordonnées logiques: (%1;%2)\nCoordonnées physiques: (%3;%4)\nZoom: %5  Nombre de lignes: %6").arg(lx).arg(ly).arg(end.x()).arg(end.y()).arg(scaleFactor).arg(scene->items().size()-3));
}

void Widget::restoreOriginalZoom(){
    setMatrix(QMatrix(matrix().m11()/scaleFactor,matrix().m12()/scaleFactor,matrix().m21()/scaleFactor,matrix().m22()/scaleFactor,0,0) );
    scaleFactor = 1.0;
}

void Widget::recompute()
{
    QRectF viewRect =  mapToScene(this->rect()).boundingRect();
    QList<QGraphicsItem *> b = scene->items(viewRect);

    for(int i = 0; i < 2; i++){
        QGraphicsLineItem* lineItem = (QGraphicsLineItem*)b.takeLast();
        Segment seg = Segment(lineItem->line());

        fractal(7,seg);
    }

    this->update();
}

void Widget::changeMode()
{
    if(editionMode){
        foreach(QGraphicsLineItem* lineItem, createdLines){
            fractal(7,Segment(lineItem->line()));
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
