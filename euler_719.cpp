//euler 719
#include <iostream>
#include "vectorheader.h"
#include <math.h>

/**
 * We define an S-number to be a natural number, n, that is a 
 * perfect square and its square root can be obtained by splitting 
 * the decimal representation of n into 2 or more numbers then 
 * adding the numbers.
 * e.g. 
 * 81:   sqrt(81) = 8 + 1 = 9
 * 6724: sqrt(6742) = 6 + 72 + 4 = 82
 * T(N) = sum of all S numbers n <= N. T(10^4) = 4133, find T(10^12)
 * 
 * e.g. n = abc: a + b + c, ab + c, a + bc
 * n = abcd: a + b + c + d, ab + b + c, ab + bc, abc + d, a + bc + d, a + bcd, a + b + cd
 */

void genIntPairs(int arr[], int n)
{
    if(n==2){
        std::cout << arr[0] << " + " << arr[1] << std::endl;
    }
    else {
        int right = n;
        int left = 0;
        for(int a = 0; a <= left; a++){
            for(int b = a+1; b < right; b++){
                std::cout << arr[b];
            }
            std::cout << " + " << arr[a];
        }
    }
    /**
     * arr[0] + (arr[1]arr[2]arr[3]...arr[n])
     * (arr[0]arr[1]) + (arr[2]arr[3]...arr[n])
     */
}

int main()
{
    std::vector<unsigned int> vec = {1, 2, 3};
    //int n = vec.size() / vec[0].size();
    //generatePermitationsVec(vec, n);
    int arr1[] = {1, 2};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << std::endl << "Next (" << n1 << "): " << std::endl;
    genIntPairs(arr1, n1);
    std::cout << std::endl << "Next (" << n2 << "): " << std::endl;
    genIntPairs(arr2, n2);
    std::cout << std::endl << "Next (" << n3 << "): " << std::endl;
    genIntPairs(arr3, n3);
    std::cout << std::endl;
    return 0;
}