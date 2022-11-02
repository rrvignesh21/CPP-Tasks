#include<iostream>
using namespace std;
/* Write a C++ program to accept an email address and throw an exception if it does not contain @ symbol. */

bool chechEmailId(string emailId){
    if(emailId.length() == 0){
        //cout << "1" << endl;
        return false;

    }
    else{
        int dot,at;
        int dotfrequency = 0,atfrequency = 0;
        for(int i = 0;i<emailId.length();i++){
            if(emailId[i] == '@'){
                at = i;
                atfrequency++;
            }
            if(emailId[i] == '.'){
                dot = i;
                dotfrequency++;
            }
        }
        if(atfrequency > 1 || dotfrequency > 1 || at > dot){
            //cout << "2" << endl;
            return false;
        }
        if(atfrequency == 1 && dotfrequency == 1 && at < dot){
            //cout << "3" << endl; 
            return true;
        }
        cout << "4" << endl;
        return false;

    }
} 

int main(){
    string emailId;
    try
    {
        cout << "Enter Email Id : ";
        cin >> emailId;
        if(!chechEmailId(emailId)){
            throw emailId;
        }
        else{
            cout << "Email id : " << emailId << endl; 
        }
    }
    catch(string invalid)
    {
        cout << invalid << " is invalid email id." << endl;
    }
    
}