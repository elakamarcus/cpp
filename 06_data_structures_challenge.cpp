//06_data_structures_challenge.cpp

//05_challenge

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

struct player {
    string name;
    int numWins;
};

const int MAX_CHIPS = 100;
const float MAX_PER_TURN = .5;

/** Prototypes */
string findPlayerName(player[], bool);
int askMove(bool player1Turn, int chipsInPile, player[]);
void getUserNames(player[]);
void addWin(player[], bool);
/** end Prototypes */

int main()
{
    bool player1Turn = true;
    // bool for when game over.
    bool gameover = false;
    int moveCounter = 0;
    int chipsInPile = 0;
    int chipsTaken = 0;

    // array of player names.
    player players[2];
    char userChoice;
    int maxPerTurn = 0;

    ofstream outFile;
    outFile.open("Winners.list", ios::app);

    getUserNames(players);
    srand(time(0));

    do
    {
        chipsInPile = (rand() % MAX_CHIPS) + 1;
        cout << "This round will start with " << chipsInPile << " chips in pile\n";
        gameover = false;
        moveCounter = 0;
        while (gameover == false)
        {
            chipsTaken = askMove(player1Turn, chipsInPile, players);
            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " left in pile\n";
            player1Turn = !player1Turn;
            moveCounter++;
            if (chipsInPile == 0)
            { 
                gameover = true;
                cout << findPlayerName(players, player1Turn) << " You won!\n";
                outFile << findPlayerName(players, player1Turn) << moveCounter << endl;
            }
        }
        cout << "Would you like to play again? (Y/N)\n";
        cin >> userChoice;
    } while (toupper(userChoice) == 'Y');
    outFile.close();
    return 0;
}

/** 
 * Functions below here
*/

void getUserNames(player players[])
{
    cout << "Player 1, please enter your name: ";
    cin >> players[0].name;
    cout << "Player 2, please enter your name\n (if you wish to play against computer, enter AI): ";
    cin >> players[1].name;
    cout << "Good luck " << players[0].name << " and " << players[1].name << endl;
    players[0].numWins = 0;
    players[1].numWins = 0;
}

string findPlayerName(player players[], bool player)
{

    if (player)
    {
        return players[0].name;
    }
    else
    {
        return players[1].name;
    }
}

int askMove(bool player1Turn, int chipsInPile, player players[])
{
    int chipsTaken = 0;
    int maxPerTurn = MAX_PER_TURN * chipsInPile;
    do
    {
        cout << findPlayerName(players, player1Turn) << " how many chips would you like?\n";
        cout << "You can take up to ";
        if (maxPerTurn == 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << maxPerTurn << endl;
        }
        if(findPlayerName(players, player1Turn) == "AI"){
            if(maxPerTurn == 0){
                chipsTaken = 1;
            }
            else {
                chipsTaken = (rand() % maxPerTurn) + 1;
            }
        }
        else {
            cin >> chipsTaken;
        }
    } while ((chipsTaken > maxPerTurn) && (chipsInPile > 1));
    return chipsTaken;
}