#include <iostream>
#include <vector>
#include <set>
#include "/home/nomnom/Documents/git/cpp/vectorheader.h"

std::vector<unsigned int> createPermutations(int n);
std::vector<unsigned int> makeVectorFromInt(int num);
std::vector<unsigned int> rotateVector(std::vector<unsigned int> &v);
bool isPrime(int n);
bool isVectorPrime(std::vector<unsigned int> &a);
void vectorsUnsPrint(const std::vector<std::vector<unsigned int>> &vec);
void vectorUnsPrint(const std::vector<unsigned int> &vec);
int makeIntFromVector(std::vector<unsigned int> n);

int main()
{
    std::vector<unsigned int> vec, primes, test, rotated;
    std::set<int> tested;
    tested.insert(2);
    tested.insert(3);
    for (int i = 3; i <= 1000000; i+=2)
    {
        if (isPrime(i))
        {
            test = makeVectorFromInt(i);
            rotated = rotateVector(test);
            if (isVectorPrime(rotated))
            {
                for (int i = 0; i < rotated.size(); i++)
                {
                    tested.insert(rotated[i]);
                }
            }
        }
    }

    std::cout << "How many circular primes < 10^6: " << tested.size() << std::endl;
    std::cout << "List circular primes:" << std::endl;
    for (auto i : tested)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    int summary=0;
    for(auto x : tested){
        summary += x;
    }
    std::cout << "Sum of circular primes <10^6: " << summary << std::endl;
    return 0;
}
