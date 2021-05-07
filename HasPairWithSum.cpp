#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool HasPairWithSum(const vector<int> data, int sum){
    unordered_set<int> comp;
    for(int value : data){
        if(!(comp.find(value) == comp.end)){
            return true;
        }
        comp.insert(sum-value);
    }
    return false;
}

int main(){
    vector<int> test(5);

    test[0] = 2;
    test[1] = 4;
    test[2] = 4;
    test[3] = 5;
    test[4] = 9;

    int sum = 9;

    HasPairWithSum(test, sum);
}