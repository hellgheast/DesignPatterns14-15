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

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);    

private:
    double scaleFactor;
    QPointF startLogic;
    QPointF endLogic;
    QPointF centerLogic;
    QGraphicsScene *scene;
    QGraphicsTextItem* txt1;
    QPen* pen;
    QAction* quitFullScreen;
    bool editionMode;

    void fractal(int, Segment a);
    void texteUpdate();
    void restoreOriginalZoom();

public slots:
    void recompute();
};

#endif // WIDGET_H
