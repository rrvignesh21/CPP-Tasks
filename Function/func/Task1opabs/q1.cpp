#include<iostream>
using namespace std;
/* Write a C++ program to overload unary operators that increment and decrement. */
class OperatorOverload{
    int number;
    public:
    void getNumber(){
        cout << "Enter Number : ";
        cin >> number;
    }
    int operator ++ (){
        return (number+10);
    }
    int operator -- (){
        return (number-10);
    }

};

int main(){
    OperatorOverload object;
    object.getNumber();
    int increment = ++object;
    int decrement = --object;
    cout << "Increment Operator overload : "<< increment << endl;
    cout << "Decrement Operator overload : "<< decrement << endl;

}