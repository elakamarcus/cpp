#include <iostream>
#include "add.cpp"

int add(int x, int y);

int main(){
    std::cout << "The sum of 4 and 5 is: " << add(4, 5) << std::endl;
    return 0;
}