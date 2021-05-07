#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<unsigned int> test1 = {11, 32, 43};
    std::set<unsigned int> vals;
    std::cout << "( ";
    for( auto x : test1){
        std::cout << x << " ";
    }
    std::cout << ")" << std::endl;
    /*
    do {
        int i = test1[0];
        vals.insert(i);
    } while(std::next_permutation(test1.begin(),test1.end()));

    for( auto x : vals){
        //std::cout << x << std::endl;
    }*/
    std::rotate(test1.begin(),test1.begin()+1,test1.end());
//    test1.insert(test1.begin(), *test1.end());
    std::cout << "( ";
    for( auto x : test1){
        std::cout << x << " ";
    }
    std::cout << ")" << std::endl;
    std::rotate(test1.begin(),test1.begin()+1,test1.end());
//    test1.insert(test1.begin(), *test1.end());
    std::cout << "( ";
    for( auto x : test1){
        std::cout << x << " ";
    }
    std::cout << ")" << std::endl;
    return 0;
}