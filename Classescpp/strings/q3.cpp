#include<iostream>
using namespace std;
/* 3(L2).  Write a C++ program to capitalize the first letter of each word of a given string.
 Words must be separated by only one space. */
int main(){
    string input_string;
    cout << "Enter the String : ";
    getline(cin,input_string);
    string result_string;
    input_string[0] -= 32;
    for(int i = 0;input_string[i] != '\0';i++){
        if(input_string[i] == ' '){
            if(isalpha(input_string[i+1])){
                result_string.push_back(' ');
                input_string[i+1] -= 32;
                result_string.push_back(input_string[i+1]);
                i = i + 1;
            }
        }
        else{
            result_string.push_back(input_string[i]);
        }
    }
    cout << "Output : "<< result_string << endl;
}