#include<iostream>
using namespace std;
/* Write a C++ program to find and print all unique elements of a given array of integers */
void uniqueArray(int Array[],int size_of_Array){
    for(int i = 0;i<size_of_Array;i++){
        int j;
        for(j = 0;j<i;j++){
            if(Array[i] == Array[j]){
                break;
            }
        }
        if(i == j){
            cout << Array[i]  << " ";
        }
    }
}
int main(){
    int size_of_Array;
    cout << "Enter the size of the Array : ";
    cin >> size_of_Array;
    int array[size_of_Array];
    cout << "Enter the Array elements : ";
    for (int i = 0; i < size_of_Array; i++)
    {
        cin >> array[i];
    }
    cout << "Unique element in this Array : ";
    uniqueArray(array,size_of_Array);
}