#include<iostream>
using namespace std;
/* To find sum of 10 natural numbers using 1-D array. */
int main(){
    int arr[10];
    for(int i = 0;i < 10;i++){
        arr[i] = i+1;
    }
    int sum = 0;
    for(int i = 0;i<10;i++){
        sum += arr[i];
    }
    cout << "Sum of 10 Natural numbers is "<<sum;
}