#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <iterator>

using std::cout;
using std::list;
using std::string;
using std::deque;
using std::back_inserter;
using std::front_inserter;
using std::make_move_iterator;

int main(){
  list<string> ls = {"spacelord", "racoon", "blue", "toad", "galaxy", "guardian"};
  
  //copy list of strings to a deque of strings
  deque<string> ds;
  copy(ls.being(), ls.end(), back_inserter(ds)); //can also use front_inserter(ds)
  
  //move deque of strings to another list of strings
  list<string> ls2(make_move_iterator(ds.begin(), make_move_iterator(ds.end())));
  
  cout << "contents of 'ls': \n"; // has contents
  for(const auto& str : ls){
    cout << str << " ";
  }
  cout << std::endl << std::endl;
 
  
  cout << "contents of 'ds': \n"; //empty because moved
  for(const auto& str : ds){
    cout << str << " ";
  }
  cout << std::endl << std::endl;
  
 cout << "contents of 'ls2': \n"; // has contents
 for(const auto& str : ls2){
   cout << str << " ";
 }
 cout << std::endl << std::endl;
  
  
  return 0;
}
