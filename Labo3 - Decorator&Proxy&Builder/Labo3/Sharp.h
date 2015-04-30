#ifndef EQUAL_H
#define EQUAL_H


class Sharp : public Decorator
{
    public:
        Sharp(Fruit * fruit);
        virtual ~Sharp();
        char getDecoration() const;
    protected:
    private:
};


#endif // EQUAL_H
