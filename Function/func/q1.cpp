#include <iostream>
using namespace std;
/* Reverse a string using Recursion */
string reverse_String(string input,string result){
    if(input.length() != 0){
       result.push_back(input.back());
       input.pop_back();
       return reverse_String(input,result);
    }
    return result;
}


int main(){
    string input_string;
    cout << "Enter the String : ";
    getline(cin,input_string);
    string reversed_string;
    reversed_string = reverse_String(input_string,reversed_string);
    cout << "Reversed String : " << reversed_string;     
}