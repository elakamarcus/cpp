#include <iostream>
using std::cout;

template <class T>
class Position {
    T x, y;
    public:
    Position(T x, T y) : x(x), y(y) {}
    void Print(){
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Position<int> p(1 ,1);
    p.Print();

    Position<double> q(10.0, 10.2);
    q.Print();

    return 0;
}