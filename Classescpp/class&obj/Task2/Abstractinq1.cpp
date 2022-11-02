#include<iostream>
using namespace std;
/* A boy has his money deposited $1000, $1500 and $2000 in banks-Bank A, Bank B and Bank C respectively. We have to print the money deposited by him in a particular bank.

Create a class 'Bank' with a function 'getBalance' which returns 0. Make its three subclasses named 'BankA', 'BankB' and 'BankC' with a function with the same name 'getBalance' which returns the amount deposited in that particular bank.
 Call the function 'getBalance' by the object of each of the three banks. */
class Bank{
    int Balance;
    public:
    Bank(){
        Balance = 0;
    }
    void deposit(){
        cout << "Enter the amount to deposit : ";
        cin >> Balance;
    }
    int getBalance(){
        return Balance;
    }
};

class BankA:public Bank{

};
class BankB:public Bank{
    
};
class BankC:public Bank{
    
};
int main(){
    BankA bankA;
    BankB bankB;
    BankC bankC;
    bankA.deposit();
    bankB.deposit();
    bankC.deposit();
    int balanceA = bankA.getBalance();
    int balanceB = bankB.getBalance();
    int balanceC = bankC.getBalance();
    cout << "Balance in Bank A : $" << balanceA << endl;
    cout << "Balance in Bank B : $" << balanceB << endl;
    cout << "Balance in Bank C : $" << balanceC << endl;
}