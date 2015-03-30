#include "fractal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fractal *w;
    w = Fractal::getInstance();
    w->show();

    return a.exec();
}
