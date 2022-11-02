#include<iostream>
using namespace std;
/* 2(L2).  Write a C++ program to change every letter in a given string
 with the letter following it in the alphabet (ie. a becomes b, p becomes q, z becomes a). */
int main(){
    char input_string[20];
    cout << "Enter the String : ";
    cin >> input_string;
    for(int i = 0; input_string[i] != '\0';i++){
        if(input_string[i] >= 97 && input_string[i] <= 122){
            if(input_string[i] == 122){
                input_string[i] = 97;
            }
            else{
                input_string[i] += 1;
            }
        }
        else if(input_string[i] >= 65 && input_string[i] <= 90){
            if(input_string[i] == 90){
                input_string[i] = 65;
            }
            else{
                input_string[i] += 1;
            }
        }
        else{
            continue;
        }
    }
    cout << "String : "<< input_string;
}