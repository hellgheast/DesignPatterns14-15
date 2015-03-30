#ifndef FRACTAL_H
#define FRACTAL_H

#include <QWidget>
#include <QLine>
#include <QVector>


class Fractal : public QWidget
{
    Q_OBJECT

public:
    static Fractal* getInstance();
    void deleteInstance();

    void setList(QVector<QLine>);

    void setRoot(QVector<QLine>);

    QVector<QLine> getList();

    ~Fractal();

private:
    Fractal(QWidget *parent = 0);
    static Fractal* single;

    QVector<QLine> listRoot;
    QVector<QLine> listLine;

};

#endif // FRACTAL_H
