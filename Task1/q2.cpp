#include<iostream>
using namespace std;
/* Write a program to read random numbers and find the summation of it, if the numbers are prime. */
bool isprime(int number);
int main(){
    int no_of_numbers;
    cout << "Enter number of numbers : ";
    cin >> no_of_numbers;
    int numbers[no_of_numbers];
    cout << "Enter the numbers: ";
    for(int i = 0;i< no_of_numbers;i++){
        cin >> numbers[i];
    }
    int sumofprime = 0;
    for (int num : numbers)
    {
        if(isprime(num)){
            sumofprime = sumofprime + num;
        }
    }
    cout << "Sum : "<< sumofprime;
    

}
bool isprime(int number){
    if(number == 0 || number == 1){
        return false;
    }    
    else{
        for(int i = 2;i < number / 2;i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;
    }
}