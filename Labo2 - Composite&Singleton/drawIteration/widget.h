#ifndef WIDGET_H
#define WIDGET_H

#include "segment.h"
#include "node.h"
#include "leafsegment.h"
#include <QtWidgets>
#include <QDialog>

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    static const int ItemDepth = 0;
    static const int ItemIsLeaf = 1;

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
    void restoreOriginalZoom();
    QPen* pen;
    QAction* quitFullScreen;
    QAction* switchToEditionOrDisplay;
    bool editionMode;
    QGraphicsLineItem* tempLineEdition;
    QList<QGraphicsLineItem*> createdLines;

    QList<Component*> components;
    void fractal2(int, LeafSegment* noeudRacine);

    void fractal(int, Segment a);
    int limite;

public slots:
    void keepDetailLevel();
    void uniformiser();
    void changeMode();
};

#endif // WIDGET_H
