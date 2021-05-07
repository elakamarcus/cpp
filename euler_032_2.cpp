#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    unsigned int Max=9;
    
    std::vector<unsigned int> digs = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    digs.resize(Max);
    
    std::set<unsigned int> val;
    do {
        for(unsigned int aVal = 1; aVal < Max; aVal++) {
            for(unsigned int bVal = 1; bVal < Max - aVal; bVal++) {
                unsigned int cVal = Max - aVal - bVal;
                if(cVal < aVal || cVal < bVal) {
                    break;
                }
                unsigned int pos = 0;
                unsigned int a = 0;
                for(unsigned int i = 1; i <= aVal; i++) {
                    a *= 10;
                    a += digs[pos++];
                }
                unsigned int b = 0;
                for(unsigned int i = 1; i <= bVal; i++) {
                    b *= 10;
                    b += digs[pos++];
                }
                unsigned int c = 0;
                for(unsigned int i = 1; i <= cVal; i++) {
                    c *= 10;
                    c += digs[pos++];
                }
                if((a * b) == c) {
                    val.insert(c);
                }
            }
        }
    } while(std::next_permutation(digs.begin(), digs.end()));
    unsigned int sum = 0;
    for(auto x : val) {
        sum += x;
    }
    std::cout << sum << std::endl;
    return 0;
}