#include <iostream>

using std::cout;

template <class T>
class my_node
{
private:
    T data;
    my_node *next;

public:
    my_node(T data, my_node *next) : data(data), next(next) {}
    T get(){return data; }                 // return type T, returns data of the node
    my_node *next_node() { return next; } //return next node as function
};

template <class T>
void swap(T &x, T &y)
{
    T z = x;
    x = y;
    y = z;
}

int main()
{
    int a = 1;
    int b = 2;
    double c = 3.0;
    swap(a, b);
    cout << "a, b: " << a << ", " << b << "\n";
    //if trying to swap a and c, there will be type error..
    //swap(a, c);

    my_node<int> n(a, nullptr);
    my_node<int> m(b, &n);
    //type error again, int and double
    //my_node<double> p(c, nullptr);

    return 0;
}