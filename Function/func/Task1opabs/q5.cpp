#include<iostream>
#include<string.h>
using namespace std;
/*  Write a C++ program to overload '+' operator to concatenate two strings. */
class AddString{
    public:
    char string[20];
    void getString(){
        cout << "Enter string 1 :";
        cin >> string;
    }
    /*
    AddString operator + (AddString string2){
        AddString string3;
 
        // Use strcat() to concat two specified string
        strcat(string, string2.string);
 
        // Copy the string to string to be return
        strcpy(string3.string, string);
 
        // return the object
        return string3;
    }
    */
    void operator + (AddString string2){
        strcat(string, string2.string);
    }
};

int main(){
    AddString string_1,string_2;
    string_1.getString();
    string_2.getString();
//    AddString result =  string_1 + string_2;
    string_1 + string_2;
    std::cout << string_1.string;
}