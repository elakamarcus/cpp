#include <iostream>

/* get n bits from position p */
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n) & ~(~0 << n));
}

int main(){

    printf("%u", getbits(6, 4, 3));

    return 0;
}