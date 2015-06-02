#ifndef LEGUME_H
#define LEGUME_H
#include <iostream>

class Legume
{
public:
    Legume();
    virtual ~Legume();

    virtual void print() = 0;
    static Legume* createLegume(int choice);
protected:
private:
};

#endif // LEGUME_H
