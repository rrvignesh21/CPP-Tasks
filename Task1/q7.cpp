#include<iostream>
using namespace std;
/* To count trailing zeros in a binary number. */
int main(){
    int number;
    cout << "enter number: ";
    cin >> number;
    int count = 0;
    while(number != 0){
        if(number & 1 == 1){
            break;
        }
        else{
            count++;
            number = number >> 1;
        }
    }
    cout<< "Number of trailing zeros is " << count;

}