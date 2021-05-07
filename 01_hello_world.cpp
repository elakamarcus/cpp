//Hello world

#include <iostream>

using namespace std;

int main(){
    string name;
    string favFood;

    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Hello, " << name << ". Nice to meet you. What is your favorite food?\n";
    cin >> favFood;
    cout << "Great! " << favFood << " is my favorite food too!\n";
    return 0;
}