#include<iostream>
using namespace std;
/* C++ Program to find Largest of two numbers using Inline function */
inline int max_of_twoint(int number_1,int number_2){
    (number_1 > number_2) ? (number_1) : (number_2);
}
int main(){
    int number_1,number_2;
    cout << "Enter two Number : ";
    cin >> number_1 >> number_2;
    int maximum = max_of_twoint(number_1,number_2);
    cout << "Maximum of "<<number_1 << " and "<<number_2 << " is "<< maximum << endl; 
}