#include<iostream>
using namespace std;
/* Program to prepare a message when an exception occurs. */
int main(){
     string username,password;
    try
    {
        cout << "Enter User Name : ";
        cin >> username;
        cout << "Enter Password  : ";
        cin >> password;
        if(password.length() < 8){
            throw password;
        }
        int countOfnumbers = 0;
        for (int i = 0; i < password.length(); i++)
        {
            if (isdigit(password[i]))
            {
                countOfnumbers++;
            }            
        }
        if(countOfnumbers == 0){
            throw countOfnumbers;
        }
        cout << "Password is valid." << endl;
        
    }
    catch(...)
    {
        cout << "Invalid password." << endl;
    }
}