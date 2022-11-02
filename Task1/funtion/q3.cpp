#include<iostream>
using namespace std;
/* Create a calculator that takes a number, a basic math operator (+,-,*,/,^), and a second number all from user input, and have it print the result of the mathematical operation.
 The mathematical operations should be wrapped inside of functions. */
int add(int num1,int num2);
int subtract(int num1,int num2);
int divide(int num1,int num2);
int multiply(int num1,int num2);
int power(int num1,int num2);
int main(){
    int num1,num2;
    char op;
    cout << "Enter the operation : ";
    cin >> num1 >> op >> num2;
    int result;
    switch (op)
    {
    case '+':
        result = add(num1,num2);
        cout << result;
        break;
    case '-':
        result = subtract(num1,num2);
        cout << result;
        break;
    case '/':
        result = divide(num1,num2);
        cout << result;
        break;
    case '*':
        result = multiply(num1,num2);
        cout << result;
        break;
    case '^':
        result = power(num1,num2);
        cout << result;
        break;
    default:
        break;
    }

}
int add(int num1,int num2){
    return (num1 + num2);
}
int subtract(int num1,int num2){
    return (num1 - num2);
}
int multiply(int num1,int num2){
    return(num1 * num2);
}
int divide(int num1,int num2){
    return (num1 / num2);
}
int power(int num1,int num2){
    int result = 1;
    for(int i = 0;i < num2;i++){
        result *= num1;
    }
    return result;
}