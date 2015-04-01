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
    void wheelEvent(QWheelEvent *);

private:
    double scaleFactor;
    QPointF startLogic;
    QPointF endLogic;
    QGraphicsScene *scene;
    void restoreOriginalZoom();
    QPen* pen;
    QAction* switchToEditionOrDisplay;
    bool editionMode;
    QGraphicsLineItem* tempLineEdition;
    QList<QGraphicsLineItem*> createdLines;

    //2 fcts inutiles
    QList<Component*> components;
    void fractal2(int, LeafSegment* noeudRacine);

    void fractal(int, Segment a);
    void createFractFromSegment(Segment segInitial);
    int limite;

public slots:
    void keepDetailLevel();
    void uniformiser();
    void changeMode();

signals:
    void scaleFactorChanged(double zoom);
};

#endif // WIDGET_H
