#include<iostream>
using namespace std;
/* To count total zeros and ones in a binary number. */
int main(){
    int number;
    cout << "Enter number : ";
    cin >> number;
    int size = sizeof(int) * 8;
    int count_1 = 0;
    int count_0 = 0;
    for(int i = 0;i < size;i++){
        if(number & (1 << i)){
            count_1++;
        }
        else{
            count_0++;
        }
    }
    cout << "Number of 1s : " << count_1 << endl;
    cout << "Number of 0s : " << count_0 << endl;
}