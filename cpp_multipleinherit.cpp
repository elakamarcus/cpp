#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using std::cout;

class Position2D {
    protected: //accessible from derived class
    double x, y;
    public:
    Position2D(): x(0), y(0) {};
    Position2D(double x, double y) : x(x), y(y) {};

    void moveTo(double a, double b){
        x = a;
        y = b;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
};

class Measure2D {
    protected: //accessible from derived class
    double area;
    double circumference;
    virtual void update() = 0;

    public:
    double getArea(){
        return area;
    }
    double getCircumference() {
        return circumference;
    }
};

class Circle : public Position2D, Measure2D {
    private:
    double radius;
    void update(){
        circumference = 2 * M_PI * radius;
        area = M_PI * radius * radius;
    }
    public:
    Circle() : Position2D(0,0), radius(0) {
        update();
    }
    Circle(double x, double y, double r) : Position2D(x, y), radius(r) {
        update();
    }

    void changeRadius(double r){
        radius = r;
        update();
    }

    void print(){
        cout << "x, y, radius: " << x << ", " << y << ", " << radius << "\n";
        cout << "area, circumference: " << area << ", " << circumference << "\n"; 
    }
};

int main(){
    Circle c1(1, 1, 2.0);
    Circle c2(2, 2, 5.5);
    c1.print();
    c2.print();

    c1.changeRadius(10.0);
    c1.print();

    return 0;
}