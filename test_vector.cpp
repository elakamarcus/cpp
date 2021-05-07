#include <vector>
#include <stdio.h>
#include <iostream>

int main(){
    std::vector<unsigned int> v1, v2;
    v1 = {1, 2, 3};
    v2 = {4, 5, 6};
    std::cout << v1*v2 << std::endl;

    return 0;
}