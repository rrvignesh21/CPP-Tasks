#include<iostream>
using namespace std;
/* Write a program that can throw integer and double exceptions in the same try block.
 Implement the exception handling blocks for both exceptions. */
int main(){
    try
    {
        int integer;
        cin >> integer;
        if(integer < 0){
            throw integer;
        }
        double double_number;
        cin>>double_number;
        if(double_number < 0){
            throw double_number;
        }
    }
    catch(int i)
    {
        cout << "integer throw " << i << endl;
    }
    catch(double di){
        cout << "Throw double : "<<di << endl;
    }
    
}