//05_file_i/o

#include <iostream>
#include <fstream>

int main(){
    ifstream inputFileA;
    ifstream inputFileB;
    string supply[10];
    int qty[10];

    inputFileA.open("filename");
    if (!inputFileA.fail()){ //if it succeeded ->
        while(inputFileA >> supply[i] >> qty[i]){
            cout << supply[i] << " " << qty[i] << endl;
            i++;
        }
    }
    inputFileA.close();

}