#include <iostream>

using std::cout;

class L
{
public:
    virtual char letter() = 0;
    virtual int number() = 0;
};

class A : public L //implement interface L. Must imlement char letter
{
public:
    char letter()
    {
        return 'A';
    }

    int number()
    {
        return 1;
    }
};

class B : public L //implement interface L.
{                  //error unless delcare char letter
public:
    char letter()
    {
        return 'B';
    }
    int number()
    {
        return 2;
    }
};

int main()
{
    A a;
    B b;

    cout << "Letter (from a.letter()): " << a.letter() << "\n";
    cout << "Letter (from b.letter()): " << b.letter() << "\n\n";

    L *lp;

    lp = &a;
    cout << "lp (&a): " << lp->letter() << "\n";

    lp = &b;
    cout << "lp (&b): " << lp->letter() << "\n";

    //this works because number is a virtual function in L.
    cout << "lp->number(): " << lp->number() << "\n";

    return 0;

}