//03_03 flow control
//03 flow control
//02 Data representation

#include <iostream>
using namespace std;

const int MAX_CHIPS = 100;
const float MAX_PER_TURN = .5;

int main()
{
    //This variable kees track of whose turn it is. We can name it playerOneTurn - when that is true, then it is player one's turn. When false, it is player 2's turn.
    // the player that takes the last chip, loses.
    bool player1Turn = true;
    // bool for when game over.
    bool gameover = false;

    int chispInPile = 0;
    int chispTaken = 0;

    // array of player names.
    string playerName[2];
    char userChoice;
    int maxPerTurn = 0;

    cout << "Player 1, please enter your name: \n";
    cin >> playerName[0];
    cout << "Player 2, please enter your name: \n";
    cin >> playerName[1];

    srand(time(0));
    //random number of chips in pile:
    //chispInPile = (rand() % 100) + 1;

    do
    {
        chispInPile = (rand() % MAX_CHIPS) + 1;
        cout << "This round will start with " << chispInPile << " chips in pile\n";
        gameover = false;
        while (gameover == false)
        {
            do
            {
                maxPerTurn = (MAX_PER_TURN * chispInPile);
                if (player1Turn)
                {
                    cout << playerName[0] << " how many chips would you like?\n";
                }
                else
                {
                    cout << playerName[1] << " how many chips would you like?\n";
                }
                cout << "You can take up to ";
                if (maxPerTurn == 0)
                {
                    cout << "1\n";
                }
                else
                {
                    cout << maxPerTurn << endl;
                }
                cin >> chispTaken;
            } while ((chispTaken > maxPerTurn) && (chispInPile > 1));

            chispInPile = chispInPile - chispTaken;
            cout << "There are " << chispInPile << " left in pile\n";
            if (chispInPile == 0)
            {
                gameover = true;
                if (player1Turn)
                {
                    cout << playerName[1] << " You won!\n";
                }
                else
                {
                    cout << playerName[0] << " You won!\n";
                }
            }
            else
            {
                player1Turn = !player1Turn;
            }
        }
        cout << "Would you like to play again? (Y/N)\n";
        cin >> userChoice;
    } while ((userChoice == 'y') || (userChoice == 'Y'));

    return 0;
}