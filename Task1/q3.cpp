#include<iostream>
using namespace std;
/* Write a program in C++ to print any pattern. */
int main(){
    int n;
    cout<< "Enter the height of pattern : ";
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j < i;j++){
        cout << '*';
        }
        cout << "\n";
    }
}