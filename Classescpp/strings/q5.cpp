#include<iostream>
using namespace std;
/* 5(L3). Write a C++ program to insert a dash character (-) between two odd numbers in a given string of numbers. */
int main(){
    string input_string;
    cout << "Enter string of Numbers : ";
    cin >> input_string;
    string temp;
    for(int i = 0;input_string[i] != '\0';i++){
        if(((input_string[i] - '0') % 2 != 0) && ((input_string[i+1] - '0') % 2 != 0)){
            temp.push_back(input_string[i]);
            temp.push_back('-');
            temp.push_back(input_string[i+1]);
            i = i + 1;
            continue;
        }
        else{
            temp.push_back(input_string[i]);
        }
    }
    cout << "Output : " << temp << endl;
}