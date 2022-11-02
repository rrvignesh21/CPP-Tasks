#include<iostream>
using namespace std;
/* Write a program that throws and catches an integer exception. Handle the exception and print its value. */
int main(){
    int denominator,numerator;
    try
    {
        cout << "Enter numerator : ";
        cin >> numerator;
        cout << "Enter Denominator : ";
        cin >> denominator;
        if(denominator == 0){
            throw denominator;
        }
        else{
            cout << "Result : " << (numerator/denominator) << endl;
        }
    }
    catch(int num)
    {
        cout << "Denominator can't be zero." << endl;
    }
    

}