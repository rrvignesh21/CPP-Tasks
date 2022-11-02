#include<iostream>
using namespace std;
/* Write a C++ program to find the number of pairs of integers 
in a given array of integers whose sum is equal to a specified number. */
int noOfPairs(int array[],int size_of_Array,int sum){
    int count = 0;
    for(int i = 0;i < size_of_Array;i++){
        for(int j = i;j < size_of_Array;j++){
            if(array[i] + array[j] == sum){
            count++;
            }
        }
    }return count;
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
    int target_sum_number;
    cout << "Enter Sum : ";
    cin >> target_sum_number;
    int count = noOfPairs(array,size_of_Array,target_sum_number);
    cout << "Number of pairs of integers in a given array of integers whose sum is equals " << target_sum_number << " is "<< count << endl;
}