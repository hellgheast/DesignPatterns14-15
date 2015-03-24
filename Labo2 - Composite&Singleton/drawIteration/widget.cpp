#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent), scaleFactor(1.0)
{
    scene = new QGraphicsScene(this);
    setMatrix(QMatrix(0.1,0,0,-0.1,0,0));
    scene->addLine(0,0,0,150,QPen(Qt::green));
    scene->addLine(0,0,150,0,QPen(Qt::red));
    txt1 = new QGraphicsTextItem();
    txt1->setMatrix(QMatrix(1,0.1,0,-1,0,this->fontMetrics().lineSpacing()*3 + 3));
    scene->addItem(txt1);
    texteUpdate();

    setScene(scene);
    setSceneRect(-500,-500,1000,1000);
    resize(800,600);

    setWindowTitle("DP - EQUIPE I - LABO 2 / Fractal");


    Segment* seg = new Segment(4650, 200, -850, -1900);
    scene->addLine(seg->getX1(), seg->getY1(), seg->getX2(), seg->getY2(),QPen(Qt::red));

    fractal(12,seg);
}

Widget::~Widget()
{

}

void Widget::fractal(int i, Segment *a)
{
    if(i == 0) return;
    --i;
    QList<Segment*> temp = a->iterer();
    foreach (Segment* seg , temp){
        scene->addLine(seg->getX1(), seg->getY1(), seg->getX2(), seg->getY2(),QPen(Qt::red));
        fractal(i,seg);
    }
}

void Widget::mousePressEvent(QMouseEvent * where){
    if(where->button() == Qt::LeftButton){
        start = where->pos();
    }
    else if(/*where->button() == Qt::RightButton ||*/ where->button() == Qt::MidButton){
        restoreOriginalZoom();
        texteUpdate();
    }
}

void Widget::mouseMoveEvent(QMouseEvent * where){
    end = where->pos();
    if((where->buttons() == Qt::LeftButton)){

        scene->addLine(QLineF(mapToScene(start),mapToScene(end)),QPen(Qt::blue));
        start = end;
    }
    else if(where->buttons()== Qt::RightButton){
         rotate(2);
    }
    texteUpdate();
}

void Widget::wheelEvent(QWheelEvent * a){
    QMatrix*  transform = new QMatrix(this->matrix().m11()/scaleFactor,this->matrix().m12()/scaleFactor,this->matrix().m21()/scaleFactor,this->matrix().m22()/scaleFactor,0,0);
    if(a->delta()>0.0){
        scaleFactor += 0.8;
    }
    else if(scaleFactor >= 1){
        scaleFactor -= 0.8;
    }

    setMatrix(QMatrix(transform->m11()*scaleFactor,transform->m12()*scaleFactor, transform->m21()*scaleFactor, transform->m22()*scaleFactor,0,0));
    texteUpdate();
}

void Widget::texteUpdate(){
    QPointF pointLog = mapToScene(end);
    QString lx = QString().number(pointLog.x(),'f',2);
    QString ly = QString().number(pointLog.y(),'f',2);
    txt1->setPlainText(QString("Coordonnées logiques: (%1;%2)\nCoordonnées physiques: (%3;%4)\nZoom: %5  Nombre de lignes: %6").arg(lx).arg(ly).arg(end.x()).arg(end.y()).arg(scaleFactor).arg(scene->items().size()-3));
}

void Widget::restoreOriginalZoom(){
    setMatrix(QMatrix(matrix().m11()/scaleFactor,matrix().m12()/scaleFactor,matrix().m21()/scaleFactor,matrix().m22()/scaleFactor,0,0) );
    scaleFactor = 1.0;
}

