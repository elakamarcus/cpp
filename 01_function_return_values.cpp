// function return values
#include <iostream>

int getValueFromUser() {
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

// void return value
void doPrint() {
    std::cout << "Print" << std:endl;
    // does not return any value
}

int main() {
    int num { getValueFromUser() };
    std::cout << num << " times two is: " << num*2 << std::endl;

    return 0;
}