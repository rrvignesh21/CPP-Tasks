#include<iostream>
using namespace std;
/* To convert decimal to binary number system using bitwise operator. */
int main(){
    int number;
    int binary = 0;
    int n_bit;
    int tn = 1;
    cout << "Enter number : ";
    cin >> number;
    while (number != 0){
        n_bit = number & 1;
        binary = binary + (tn * n_bit);
        tn = tn * 10;
        number = number >> 1;
    }
    cout << "Binary Number of is " << binary << endl;

}