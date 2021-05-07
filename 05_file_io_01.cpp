//05_file_i/o

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inputFileA;
    std::string phrase;
    int userGuess = 0;
    inputFileA.open("dumbfile");
    if (!inputFileA.fail())
    { //if it succeeded ->
        while (inputFileA >> phrase)
        {
            std::cout << "The phrase is: " << phrase << std::endl;
            std::cout << "What is your answer?\n";
            std::cin >> userGuess;
            if (userGuess == phrase.length()){
                std::cout << "Congrats..lol\n";
            }
            else {
                std::cout << "Try again... later\n";
            }
        }
    }
    inputFileA.close();
}