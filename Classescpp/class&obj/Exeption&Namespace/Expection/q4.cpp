#include<iostream>
#include<math.h>
using namespace std;
/* Program to handle the exception when the power value of X^n is a negative value. i.e n is negative. */
int main(){
    int base,exponent;
    try
    {
        cout << "Enter base : ";
        cin >> base;
        cout << "Enter exponent : ";
        cin >> exponent;
        if(exponent < 0){
            throw exponent;
        }
        else{
           cout << "Power : " <<  pow(base,exponent) << endl;            
        }
    }
    catch(int exponent)
    {
        cout << "Exponent is negative." << endl;
    }
    
}