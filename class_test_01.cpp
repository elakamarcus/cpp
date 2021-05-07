#include <iostream>
#include <string>



class Sprite {
    std::string name;
    int x, y;

public:
    Sprite();
    Sprite(std::string s);
    Sprite(int i, int j);
    Sprite(std::string s, int i, int j);

    void print(){
        std::cout << name << "\t: {" << x << ", " << y << "}" << std::endl;
    }
};

Sprite::Sprite(){
    name = "Incognito_1";
    x = 10;
    y = 10;
}
Sprite::Sprite(std::string s){
    name = s;
    x = 0;
    y = 0;
}
Sprite::Sprite(int i, int j){
    name = "Incognito_2";
    x = i;
    y = j;
}
Sprite::Sprite(std::string s, int i, int j){
    name = s;
    x = i;
    y = j;
}

int main() {
    Sprite s("John doe", 1, 2);
    s.print();

    Sprite s2;
    s2.print();

    Sprite s3("Mr. Smith");
    s3.print();

    Sprite s4(3, 5);
    s4.print();

    std::cout << std::endl;

    Sprite *p = new Sprite("Pointy Ptr", 13, 37);
    p->print();
    std::cout << &p << std::endl;
    delete p;

    return 0;
}