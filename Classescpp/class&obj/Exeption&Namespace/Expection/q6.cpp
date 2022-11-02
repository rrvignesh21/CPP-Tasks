#include<iostream>
#include<string>
using namespace std;
/* Write a C++ program to accept user name and password and
 throw an exception if the password has less than 8 characters or does not contain a digit. */
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
    catch(string password)
    {
        cout << "Need 8 or more character in  the password." << endl;
    }
    catch(int number){
        cout << "There is no digits in the password." << endl;
    }
}