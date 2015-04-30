#ifndef WIDGET_H
#define WIDGET_H

#include "fractal.h"
#include <QtWidgets>
#include <QDialog>

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(int _deepness, QWidget *parent = 0);
    ~Widget();

    QAction *getSwitchToEditionOrDisplay() const;

protected:

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);

private:
    //Zoom
    double scaleFactor;
    double zoomStep;
    void restoreOriginalZoom();

    //Explore/Edition mode
    bool editionMode;
    QGraphicsLineItem *tempLineEdition;
    QPointF startLogic;
    QPointF endLogic;

    //Général
    QGraphicsScene *scene;
    QPen *pen;
    Fractal *fractal;
    int deepness;
    QList<QLineF> editionLines;

public slots:
    void changeMode();
    void redraw(int newDeepness);

signals:
    void scaleFactorChanged(double zoom);
    void zoomLimitReached(bool isMaxZoom);
    void switchMode(bool toEditionMode);
};

#endif // WIDGET_H
