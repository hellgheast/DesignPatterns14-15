#ifndef WIDGET_H
#define WIDGET_H

#include "segment.h"
#include "fractal.h"
#include <QtWidgets>
#include <QDialog>

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
    void wheelEvent(QWheelEvent *);

private:
    //Zoom
    double scaleFactor;
    double zoomStep;
    void restoreOriginalZoom();

    //Display/Edition mode
    QAction* switchToEditionOrDisplay;
    bool editionMode;
    QGraphicsLineItem* tempLineEdition;
    QPointF startLogic;
    QPointF endLogic;

    //Général
    QGraphicsScene *scene;
    QPen* pen;
    Fractal * fractal;
    int limite;

public slots:
    void keepDetailLevel();
    void uniformiser();
    void changeMode();

signals:
    void scaleFactorChanged(double zoom);
};

#endif // WIDGET_H
