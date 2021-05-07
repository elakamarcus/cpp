/** 
 * Header file for working with vectors
*/
#include <vector>
#include <algorithm>

// helper functions
int reverseInt(int n)
{
    int r, rev = 0;
    while (n != 0)
    {
        r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }
    return rev;
}

bool isPrime(int n)
{
	if (n % 2 == 0)
		return (n == 2);

	for (int d = 3; d * d <= n; d += 2)
		if (n % d == 0)
			return false;

	return true;
}
// end helper function

/* convert one dimensional vector / matrice to int */
int makeIntFromVector(std::vector<unsigned int> n)
{
    int m = 0;
    std::reverse(n.begin(), n.end());
    int dec = 1;
    for (auto &it : n)
    {
        m += it * dec;
        dec *= 10;
    }
    return m;
}

void vectorUnsPrint(const std::vector<unsigned int> &vec)
{
    std::cout << "(";
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << ")" << std::endl;
}

void vectorsUnsPrint(const std::vector<std::vector<unsigned int>> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
        }
        std::cout << " ";
    }
}

std::vector<unsigned int> rotateVector(std::vector<unsigned int> &v)
{
    std::vector<unsigned int> arr;
    for (int i = 0; i < v.size(); i++)
    {
        std::rotate(v.begin(), v.begin() + 1, v.end());
        int x = makeIntFromVector(v);
        arr.push_back(x);
    }
    return arr;
}

std::vector<unsigned int> makeVectorFromInt(int num)
{
    num = reverseInt(num);
    int digit;
    int temp = num;
    std::vector<unsigned int> numarr;
    while (temp > 0)
    {
        digit = temp % 10;
        temp = temp / 10;
        numarr.push_back(digit);
    }
    return numarr;
}

/* create permutation of vector, from an int returned in vector */
std::vector<unsigned int> createPermutations(int n){
    std::vector<unsigned int>m, perms;
    m = makeVectorFromInt(n);
    do{
        int i = makeIntFromVector(m);
        perms.push_back(i);
    }
    while(std::next_permutation(m.begin(), m.end()));
    return perms;
}

/* check whether all ints in vector are primes */
bool isVectorPrime(std::vector<unsigned int> &a)
{
    bool flag = false;
    for (int i = 0; i < a.size(); i++)
    {
        flag = isPrime(a[i]);
        if (!flag)
        {
            return flag;
            break;
        }
    }
    return flag;
}
