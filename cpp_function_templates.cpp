#include <iostream>
#include <string>
using std::string;
using std::cout;

template <class T>
T DoubleIt(T x){
    return x + x; //the type needs to support + operator..
}

int main(){
    cout << "Double 5: " << DoubleIt(5) << "\n";
    cout << "Double 1.5: " << DoubleIt(1.5) << "\n";
    cout << "Double true: " << std::boolalpha << DoubleIt(true) << "\n";
    //cout << "Double const char* \"Hello\": " << DoubleIt("Hello") << "\n";
    // above is a pointer, class cannot add pointer to itself.
    string s = "World";
    cout << "Double string \"World\": " << DoubleIt(s) << "\n";
}