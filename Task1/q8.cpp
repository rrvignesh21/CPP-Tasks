#include<iostream>
using namespace std;
/* To count leading zeros in a binary number. */
int main(){
    int number;
    cout << "Enter number: ";
    cin >> number;
    int size = sizeof(int) * 8;
    int x = 1 << (size - 1);
    int count = 0;
    for(int i = 0;i < size;i++){
        if((number << i) & x){
            break;
        }
        count++;
    }
    cout << "Number of leading zeros is : " << count;
}