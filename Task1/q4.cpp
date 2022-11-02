#include<iostream>
using namespace std;
/* Program to find the Fibonacci series till the given number of terms. */
int main(){
    int number_of_term;
    cout << "Enter the number of term : ";
    cin >> number_of_term;
    int n1 = 0;
    int n2 = 1;
    int nextterm;
    for(int i = 1;i <= number_of_term;i++){
    if(i == 1){
        cout << n1 << " ";
        continue;
    }
    if(i == 2){
        cout << n2 << " ";
        continue;
    }
    nextterm = n1 + n2;
    n1 = n2;
    n2 = nextterm;
    cout << nextterm << " ";
    }
    return 0;
    
}