//05_file_io_o

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream inStream;
    inStream.open("dumbfile");
    ofstream outStream;
    outStream.open("newDumbfile"); // ios::app to append.

    int userGuess = 0;
    string phrase;

    if (!inStream.fail()){
        while(inStream >> phrase){
            cout << "The phrase is: " << phrase << endl;
            cout << "What is your guess?\n";
            cin >> userGuess;
            if(userGuess == phrase.length()){
                cout << "Congrats, lul\n";
            }
            else {
                cout << "No, wrong. Bad user, Bad!\n";
                outStream << phrase << endl;
            }
        }
    }
    inStream.close();
    outStream.close();
}