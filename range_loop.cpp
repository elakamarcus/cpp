#include <cstdio>

using namespace std;

int main() {
    int array[] = {1, 2, 3, 4, 5};

    for( int i : array){
        printf("i is: %d\n", i);
    }
    return 0;
}