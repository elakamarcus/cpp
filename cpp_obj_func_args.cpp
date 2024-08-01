#include <iostream>
#include <string>

using std::cout;
using std::string;

/// @brief Sprite class with public accessible function
class Sprite
{
    string name;
    int x, y;

public:
    Sprite() : name(""), x(0), y(0) {};
    Sprite(string s, int a, int b) : name(s), x(a), y(b) {};

    void print() const{
        cout << name << " @ (" << x << ", " << y << ")" << std::endl;
    }
};
/// @brief Should restrict this to one Sprite object, to make the code more generic
/// @param a First Sprite to output
/// @param b Second Sprite to output
/// @param c Third Sprite to output
void SpriteOutput(const Sprite a, const Sprite *b, const Sprite& c) {
    cout << "\n";
    cout << "a: " << &a << "\n";
    a.print();
    cout << "\n";

    cout << "b: " << b << "\n";
    b->print();
    cout << "\n";

    cout << "c: " << &c << "\n";
    c.print();
    cout << "\n";
}

int main(){
    Sprite a("Alice", 0, 0),
    b("Beatrice", 13, 37),
    c("Chase", 5, 15);

    cout << "a: " << &a << "\n";
    cout << "b: " << &b << "\n";
    cout << "c: " << &c << "\n";
    SpriteOutput(a, &b, c);

    return 0;

}