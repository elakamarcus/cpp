#include <iostream>

using std::cout;

class A {
    public:
    //allow overwriting the function in derived classes / child classes
    virtual char letter(){
        return 'A';
    }
};

class B : public A{
    public:
    char letter() {
        return 'B';
    }
};

int main(){
    B b;
    A *a = &b;
    A &a2 = b;
    //although *a and &a2 are pointer or ref to B::b, dot or arrow will using class A function, unless the function in A is virtual.
    cout << "Letter (from a->letter()): " << a->letter() << "\n";
    cout << "Letter (from b.letter()): " << b.letter() << "\n";
    cout << "Letter (from a2.letter()): " << a2.letter() << "\n";

    return 0;

}