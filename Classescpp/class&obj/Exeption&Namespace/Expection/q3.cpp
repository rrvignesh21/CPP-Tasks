#include<iostream>
using namespace std;
/* Program to throw the size and handle the exception when the user reads the size of an array as a negative value. */
int main(){
    try
    {
        int size;
        cout << "Enter the size of array : ";
        cin >> size;
        if(size < 0){
            throw size;
        }
        else{
            int array[size];
            cout << "Enter the array elements : ";
            for(int i = 0;i<size;i++){
                cin >> array[i];
            }
            cout << "Array : ";
            for(int i = 0;i<size;i++){
                cout << array[i] << " ";
            }
        }
    }
    catch(int exp)
    {
        cout << "Size of array can't be negative."<<endl;
    }
    
}