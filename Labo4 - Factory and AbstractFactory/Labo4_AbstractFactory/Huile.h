#ifndef HUILE_H
#define HUILE_H
#include <iostream>

class Huile
{
public:
    Huile();
    virtual ~Huile();

    virtual void print() = 0;
    static Huile* createHuile(int choice);
protected:
private:
};

#endif // HUILE_H
