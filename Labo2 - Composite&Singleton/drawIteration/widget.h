#ifndef WIDGET_H
#define WIDGET_H

#include "fractal.h"
#include <QtWidgets>
#include <QDialog>

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QAction *getSwitchToEditionOrDisplay() const;

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
    void zoomLimitReached(bool isMaxZoom);
    void switchMode(bool toEditionMode);
};

#endif // WIDGET_H
