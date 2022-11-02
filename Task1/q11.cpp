#include<iostream>
using namespace std;
/* To rotate bits of a given number. */
#define SIZE sizeof(int)*8
int leftrotate(int number,int n);
int rightrotate(int number,int n);
int main(){
    int number;
    cout << "Enter the number : ";
    cin >> number;
    cout << "How many bits to rotate : ";
    int n;
    cin >> n;
    int left = leftrotate(number,n);
    int right = rightrotate(number,n);
    cout << "Left rotate "<< n << " bits : " << left << endl;
    cout << "right rotate "<< n << " bits : " << right << endl; 
    
}
int leftrotate(int number,int n){
    return ((number << n) | (number >> (SIZE - n))); 
}

int rightrotate(int number,int n){
    return ((number >> n) | (number << (SIZE - n)));
}