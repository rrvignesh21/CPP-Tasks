#include<iostream>
using namespace std;
/* C++ Program to Find Power Using Recursion. */
int calculatePower(int base,int power,int result){
    if(power != 0){
        result *= base;
        return calculatePower(base,power - 1,result);          
    }
    return result;
        
}

int main(){
    int base,power;
    cout << "Enter base and Power : ";
    cin >> base >> power;
    int result = calculatePower(base,power,1);
    cout<<" power :  " << result << endl;
}