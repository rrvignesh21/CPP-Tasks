#include<iostream>
/* Write a program in C++ to input a single digit number and print a rectangular form of 5 columns and 5 rows. */
using namespace std;
int main(){
    int number;
    cout << "Enter a Single digit number:";
    cin >> number;
    for (int i = 0;i < 5;i++){
        if(i == 0 || i == 4){
        for(int j = 0;j<5;j++){
            cout << number << " ";
        }
        cout << "\n";
        }
        else{
        cout << number <<"       "<< number<< "\n"; 
        }       
    }    
}