#include<iostream>
using namespace std;
/*  Write a C++ program to find the largest word in a given string. */
int main(){
    string input_string;
    cout << "Enter the String : ";
    getline(cin,input_string);
    string output_string;
    string temp;
    int maximum_length = 0;
    for(int i = 0;input_string[i] != '\0';i++){
        if(isalpha(input_string[i])){
            temp.push_back(input_string[i]);
        }
        else{
            if(maximum_length < temp.length()){
                output_string = temp;
                maximum_length = temp.length();
                temp.clear();
            }
            else{
                temp.clear();
            }
        }
    }
    
    cout << "Largest word in the given string : "<< output_string;

}