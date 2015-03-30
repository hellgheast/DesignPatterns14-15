#include "fractal.h"

Fractal* Fractal::single=0;

Fractal::Fractal(QWidget *parent)
    : QWidget(parent)
{

}

Fractal::~Fractal()
{

}

Fractal* Fractal::getInstance()
{
    if(!single)
    {
        single = new Fractal();
        return single;
    }else{return single;}
}

void Fractal::deleteInstance()
{
    delete(single);
}

QVector<QLine> Fractal::getList()
{
    return listLine;
}

void Fractal::setList(QVector<QLine> list)
{
    listLine = list;
}

void Fractal::setRoot(QVector<QLine> root)
{
    listRoot = root;
}
