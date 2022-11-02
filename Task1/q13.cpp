#include<iostream>
using namespace std;
/* To swap two numbers using bitwise operator. */
int main(){
    int number_1,number_2;
    cout << "Enter two numbers : ";
    cin >> number_1 >> number_2;
    cout << "Before Swapping : " << endl;
    cout << "Number 1 : " << number_1 << endl;
    cout << "Number 2 : " << number_2 << endl;
    number_1 = number_1 ^ number_2;
    number_2 = number_1 ^ number_2;
    number_1 = number_1 ^ number_2;
    cout << "After Swapping : " << endl;
    cout << "Number 1 : " << number_1 << endl;
    cout << "Number 2 : " << number_2 << endl;

}