#include <iostream>
#include <string>

//can access given class private members and methods

using std::cout;
using std::string;

class Sprite
{
    string name;
    int x, y;
    friend class Forest; //asymetric relationship
public:
    Sprite() : name(""), x(0), y(0){};
    Sprite(string s, int a, int b) : name(s), x(a), y(b){};

    void print()
    {
        cout << name << " @ (" << x << ", " << y << "\n";
    }
};

class Forest
{
    Sprite a[10];
    //need to declare friend class here, to make the relationship symetric
public:
    Forest()
    {
        char c = 'A';
        for (int i = 0; i < 10; i++)
        {
            a[i].name = string(1, c + i);
            a[i].x = i-1;
            a[i].y = i;
        }
    }

    void print(){
        for (int i=0; i<10; i++){
            cout << a[i].name << " ";
        }
        cout << "\n";
    }
};

int main(){
    Forest f;
    f.print();

    return 0;
}