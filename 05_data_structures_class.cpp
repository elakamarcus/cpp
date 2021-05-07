//05_data_structures_class.cpp

#include <iostream>

using namespace std;

/** 
 * A class can have data stored of different data types, and also functions on those atributes!
*/
class BankAccount
{
private:
    float balance;

public:
    BankAccount(); // <-- this is a constructor.
    void Deposit(float);
    void WithDraw();
    float getBalance();
};

/** 
 * Define the feature functions of the class
*/
BankAccount::BankAccount()
{
    balance = 0;
}
float BankAccount::getBalance()
{
    return balance;
}

void BankAccount::Deposit(float dep){
    balance = balance + dep;
}

int main()
{
    BankAccount checking; // have balance, and three functions available.
    BankAccount savings;

    cout << "Checking balance is: " << checking.getBalance() << endl;
    cout << "Savings balance is: " << savings.getBalance() << endl;

    checking.Deposit(100);
    savings.Deposit(500);
    cout << "Checking balance is: " << checking.getBalance() << endl;
    cout << "Savings balance is: " << savings.getBalance() << endl;
}