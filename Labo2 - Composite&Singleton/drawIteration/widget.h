#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "segment.h"
#include <QPainter>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *);

private:
    QList<Segment*> segs;
    void fractal(int, Segment*a);
};

#endif // WIDGET_H
