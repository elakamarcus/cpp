// Euler32
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <algorithm>

int numberOfIntDigits(int n)
{
    int num = 0;
    do
    {
        ++num;
        n /= 10;
    } while (n);

    return num;
}

std::vector<int> makeVector(int num)
{

    int digit;
    int temp = num;
    std::vector<int> numarr;
    while (temp > 0)
    {
        digit = temp % 10;
        temp = temp / 10;
        numarr.push_back(digit);
    }
    return numarr;
}

bool vectorNotEqual(std::vector<int> a, std::vector<int> b)
{
    for (auto i = a.begin(); i != a.end(); i++)
    {
        for (auto j = b.begin(); j != b.end(); j++)
        {
            if (*i == *j)
            {
                return false;
            }
        }
    }
    return true;
}

void vectorPrint(std::vector<int> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i;
    }
}

int main()
{
    unsigned int D;
    std::cin >> D;

    std::vector<unsigned int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    digits.resize(D);
    std::set<unsigned int> val;
    do
    {
        for (unsigned int A = 1; A < D; A++)
        {
            for (unsigned int B = 1; B < D - A; B++)
            {
                unsigned int C = D - A - D;
                if (C < A || C < B)
                {
                    break;
                }
                unsigned int pos = 0;
                unsigned int a = 0;
                for (unsigned int i = 1; i <= A; i++)
                {
                    a *= 10;
                    a += digits[pos++];
                }
                unsigned int b = 0;
                for (unsigned int i = 1; i <= B; i++)
                {
                    b *= 10;
                    b += digits[pos++];
                }
                unsigned int c = 0;
                for (unsigned int i = 1; i <= C; i++)
                {
                    c *= 10;
                    c += digits[pos++];
                }
                if ((a * b) == c)
                {
                    val.insert(c);
                }
            }
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    unsigned int sum = 0;
    for (auto x : val)
    {
        sum += x;
    }

    std::cout << "sum: " << sum << std::endl;
    return 0;
}