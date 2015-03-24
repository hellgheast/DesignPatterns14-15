#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "segment.h"
#include <QPainter>
#include <QtWidgets>

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    //void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);

private:
    QList<Segment*> segs;
    void fractal(int, Segment*a);

protected:


private:
    double scaleFactor;
    QPoint start;
    QPoint end;
    QGraphicsScene *scene;
    QGraphicsTextItem* txt1;

    void texteUpdate();
    void restoreOriginalZoom();
};

#endif // WIDGET_H
