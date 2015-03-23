#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("hello");
    this->resize(500,500);
    Segment* a = new Segment(400, 400, 200, 200);
    segs.append(a);
    fractal(6,a);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setWindow(0,500,500,-500);
    foreach (Segment* seg , segs){
        painter.drawLine(seg->getX1(), seg->getY1(), seg->getX2(), seg->getY2());
    }

}

void Widget::fractal(int i, Segment *a)
{
    if(i == 0) return;
    --i;
    QList<Segment*> temp = a->iterer();
    foreach (Segment* seg , temp){
        segs.append(seg);
        fractal(i,seg);
    }
}

