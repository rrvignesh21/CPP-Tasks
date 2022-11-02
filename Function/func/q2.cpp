#include<iostream>
using namespace std;
/* C++ Program to implement Linear Search using recursion */
int linearSearch(int arr[],int length,int searching_value,int index){
    if(index < length){
        if(arr[index] == searching_value){
            return index;
        }
        else{
            linearSearch(arr,length,searching_value,index+1);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int size_of_Array;
    cout << "Enter the size of the array : ";
    cin >> size_of_Array;
    int array[size_of_Array];
    cout << "Enter the elements : ";
    for(int i = 0;i < size_of_Array;i++){
        cin >> array[i];
    }
    int searching_value;
    cout << "Enter the searching value : ";
    cin >> searching_value;
    int position_of_value = linearSearch(array,size_of_Array,searching_value,0);
    if(position_of_value > 0){
        cout << searching_value << " is in index " << position_of_value << "  of the array.";
    }
    else{
        cout << searching_value << " is not in this array.";
    }
}