#include<iostream>
using namespace std;
/* To flip bits of a binary number using bitwise operator. */
int main(){
    int number;
    cout << "Enter number : ";
    cin >> number;
    cout << "Number after bits are flipped : " << ~number;
}