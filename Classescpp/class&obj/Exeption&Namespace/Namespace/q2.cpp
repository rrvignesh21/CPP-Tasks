#include<iostream>
using namespace std;
/* Write a code to use unnamed namespaces. */
namespace {
    int number1;
    int number2;
    int sum;
}
int main(){
    cout << "Enter number 1 : ";
    cin >> number1;
    cout << "Enter number 2 : ";
    cin >> number2;
    sum = number1 + number2;
    cout << "Sum : "<< sum <<endl;
}