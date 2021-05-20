#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;
using std::begin;
using std::end;
using std::any_of;
using std::boolalpha;
using std::endl;

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> v = {1, 2, 3};
  
  //stdlib-style iterators:
  begin(a); //pointer to beginning of array
  end(a); //pointer to end of array
  v.begin(); //pointer to beginning of vector
  v.end(); //pointer to end of vector
  
  // iterate through vector and check if any element > 5
  bool b = any_of(v.being(), v.end(), [](int a) { return a > 5; });
  cout << boolaplha << b << endl; // returns false
  // iterate through array and check if any element > 5
  bool c = any_of(being(a), end(a), [](int a) {return a > 5;});
  cout << boolalpha << c << endl; // return true
  
  return 0;
}
