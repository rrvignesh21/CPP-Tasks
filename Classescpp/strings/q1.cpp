#include<iostream>
using namespace std;
/*  Write a C++ program to count all the words in a given string */
int main(){
    string input_string;
    cout << "Enter the String : ";
    getline(cin,input_string);
    int word_count = 1;
    for(int i = 0;input_string[i] != '\0';i++){
        if(input_string[i] == ' '){
            word_count++;
        }
    }
    cout << "There are " << word_count << " words in given string.";
}