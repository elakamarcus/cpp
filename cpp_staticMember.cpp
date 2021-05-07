#include <iostream>
#include <string>

using std::cout;
using std::string;

class X
{
    string name;
public:
    static int count;

    X(string name) : name(name)
    {
        //constructor
        count++;
    }
    ~X() //destructor
    {
        count--;
    }
};

class Y : X {
    static int one;
    public:
    static int two;
};

//what is this? a global value of X accessible from everywhere?
int X::count = 0;

int main(){
    X x("Hello"), y("Hi"), z("Nihao");

    cout << "1. count: " << X::count << "\n";
    X *t = new X("Allou");
    cout << "2. count (new): " << X::count << "\n";
    delete t;
    cout << "3. count  (del): " << X::count << "\n";
    return 0;
}