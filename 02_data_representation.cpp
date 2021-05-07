//02 Data representation

#include <iostream>
using namespace std;

/** 
 * integer = 4 bytes
 * bool = 1 byte
 * double = 
 * long = 
*/

/** 
 * variable casting:
 * int numEggs = 3;
 * cout << static_cast<int>(numEggs * 1.5);
 * 
 * rouding:
 * #include <cmath>
 * int taxRate = ceil(4.999999); -> 5.0, floor(int) = down.
 * int remainder = 6 % 2; ... 6/2 = 3, R0
 * int remainder = 6/4; .... R=2
 * fabs = absolute value of float.
 * rand() = standard library
 * dice = rand()%6 + 1; 
 * srand(time(0)); add a seed to the random number generation, to make sure we get a random number all the time.
*/

/*
int main(){
    int dice = 0;

    //seed the randomg number generator
    srand(time(0));

    dice = (rand()%6) + 1;
    cout << "You rolled a: " << dice << endl;

    return 0;
} */

/** 
 * Constant 'variables'
 */

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
    int maxPerTurn = 0;
    // array of player names.
    string playerName[2];
    //playerName[N] = "string";
    cout << "Player 1, please enter your name: \n";
    cin >> playerName[0];
    cout << "Player 2, please enter your name: \n";
    cin >> playerName[1];

    /*
   cout << "How many chips would you like in your starting pile?\n";
   cin >> chispInPile;
   */
    // seed the rng:
    srand(time(0));
    //random number of chips in pile:
    //chispInPile = (rand() % 100) + 1;
    chispInPile = (rand() % MAX_CHIPS) + 1;
    cout << "This round will start with " << chispInPile << " chips in pile\n";

    /** 
     * How many chips can user take per each turn:
    */
   //cout << "You can only take " << static_cast<int>(chispInPile * MAX_PER_TURN) << endl;
   //No need to use static_cast with below line:
   maxPerTurn = (MAX_PER_TURN * chispInPile);

   cout << "You can take up to " << maxPerTurn << endl;
   chispTaken = (rand() % maxPerTurn) + 1;
   cout << "Number of chips taken: " << chispTaken << endl;

    return 0;
}