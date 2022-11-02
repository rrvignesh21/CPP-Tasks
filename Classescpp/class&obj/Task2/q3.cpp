#include<iostream>
using namespace std;
/* Create a class to print an integer and a character using two functions having the same name 
but different sequence of the integer and the character parameters.

For example, if the parameters of the first function are of the form (int n, char c), then that of the second function will be of the form (char c, int n). */
class twofunction{
    public:
    void function(int number,char character){
        cout << "integer : "<< number<<endl;
        cout << "Character : "<<character << endl;
    }
    void function(char character,int number){
        cout << "integer : " << number << endl;
        cout << "Character : " << character << endl;
    }
};
int main(){
    int number;
    char character;
    cout << "Enter a number and a character : ";
    cin >>number>>character;
    twofunction functionclass;
    functionclass.function(character,number);
    functionclass.function(number,character);
}