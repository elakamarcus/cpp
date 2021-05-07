#include <iostream>

int getValueFromUser() {
    std::cout << "Enter integer: ";
    int input{0};
    std::cin >> input;

    return input;
}

void printDouble(int value) {
    std::cout << value << " double is: " << value * 2 << std::endl;
}
int main() {
    /*
    int num { getValueFromUser() };
    printDouble(num);
    */
    printDouble(getValueFromUser());
    return 0;
}