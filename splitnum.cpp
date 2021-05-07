#include <iostream>
#include <stack>

void splitInt(int number);
void fastSplitInt(int number);

int main(){
    int a = 456;
    std::cout << a << std::endl;
    splitInt(a);
}

void fastSplitInt(int number){
    std::stack<int>sd;
    int sum = 1;
    int a;
    while(number > 0){
        a = (number % 10);
        number /= 10;
        sd.push(a);
        sum *= a;
    }
    std::cout<<std::endl<<sum<<std::endl;

}

void splitInt(int number){
    std::stack<int> sd;
    int sum = 1;
    while(number > 0) {
        int digit = number % 10;
        number /= 10;
        sd.push(digit);
    }
    while(!sd.empty()){
        int digit = sd.top();
        sd.pop();
        sum *= digit;
        std::cout << digit << " ";
    }
    std::cout << std::endl << sum << std::endl;

}