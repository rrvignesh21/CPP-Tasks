#include<iostream>
using namespace std;
/* Write a C++ program to find the second smallest elements in a given array of integers. */
int secondSmallest(int array[],int size_of_array){
    int first_smallest = 0;
    int second_smallest = -1;
    for(int i = 1;i < size_of_array;i++){
        if(array[i] < array[first_smallest]){
            second_smallest = first_smallest;
            first_smallest = i;
        }
        else if(array[i] > array[first_smallest]){
            if(array[i] < array[second_smallest] || second_smallest == -1){
                second_smallest = i;
            }
        }
    }  
    return second_smallest;
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
    cout << "Second Smallest of this Array : "<< array[secondSmallest(array,size_of_Array)] << endl;
}