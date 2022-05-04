#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::sort;
using std::merge;
using std::all_of;
using std::for_each;

int main(){
    vector<int> v = {0, 10, 30, 20, 50};
    vector<int> w = {8, 4, 2, 6, 12};
    vector<int> t(v.size() + w.size());

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    merge(v.begin(), v.end(), w.begin(), w.end(), t.begin());
    bool b = any_of(t.begin(), t.end(), [](int i){return (i % 2) != 0;});
    cout << "odd values? " << std::boolalpha << b << std::endl;

    for_each(t.begin(), t.end(), [](int i){
        cout << i << " ";
    });
    cout << "\n"; 

    fill(t.begin(), t.end(), 0); // fill with zeroes

    for_each(t.begin(), t.end(), [](int i) {
        cout << i << " ";
    });

    cout << "\n";

}