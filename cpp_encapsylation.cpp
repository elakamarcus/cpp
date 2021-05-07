//encapsulations is done through classes, its memberfunctions and members

#define _USe_MATH_DEFINES
#include <cmath>
#include <iostream>
using std::cout;

class Circle {
    private:

    //set all variables to private, to ensure it cannot change outside of the class
    double radius;
    double x, y;

    double circumference;
    double area;

    void update(){
        circumference = 2 * M_PI * radius;
        area = M_PI * radius * radius;
    }

    public:

    Circle(double a, double b, double r) : x(a), y(b), radius(r) {
        update();
    }

    void changeRadius(double r){
        radius = r;
        update();
    }

    void changePosition(double a, double b){
        x = a;
        y = b;
    }

    double getArea(){
        return area;
    }

    double getCircumference(){
        return circumference;
    }

    void print(){
        cout << "x, y, radius: " << x << ", " << y << ", " << radius << "\n";
        cout << "area, circumference: " << area << ", " << circumference << "\n";
    }
};

int main(){
    Circle c(1.0, 1.0, 2.0);
    c.print();
    c.changeRadius(5.5);
    c.print();

    return 0;
}
