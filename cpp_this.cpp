#include <iostream>

using std::cout;

class X {
    public:
    int i;

    void start(int j) {
        i = j;
        //introduce i again, with potential ambiguity.
        for(int i=0;i<10;i++){
            cout << (i * this->i) << " ";
        }
        cout << "\n";
    }
};

int main(){
    X x;
    x.start(5);

    return 0;
}