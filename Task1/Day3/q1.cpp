#include<iostream>
using namespace std;
/* Find the Factorial of a number even when the user is not provided input for n=5(default value). */
int factorial(int n = 5){
    int result = 1;
    for(int i = 1;i <= n;i++){
        result *= i;
    }
   return result; 
}

int main(){
    int n;
    int result = factorial();
    cout << "result when no argument is passed : " << result << endl;
    cout << "Enter n :";
    cin >> n;
    result = factorial(n);
    cout << result;
}