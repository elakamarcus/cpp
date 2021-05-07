#include <iostream>
#include <string>
//permission to access class priviate member variables and methods
using std::cout;
using std::string;

class X {
    string name;
    public:
    X(string name) : name(name) {}

    friend void OutputName(X& x);
};

// function is not within function of the class, missing X::func..
void OutputName(X& x){
    cout << x.name << "\n";
}

int main(){
    X a("Alice");
    X b("Bob");

    OutputName(a);
    OutputName(b);

    return 0;
}