#include<iostream>
using namespace std;
/* Write a C++ program to find the largest three elements in an array. */
void largestThreeElements(int array[],int size_of_array){
    int first_largest = 0,second_largest = -1,third_largest = -1;
    for(int i = 1;i < size_of_array;i++){
        if(array[i] > array[first_largest]){
            third_largest = second_largest;
            second_largest = first_largest;
            first_largest = i;
        }
        else if(array[i] < array[first_largest]){
            if(second_largest == -1 || array[second_largest] < array[i]){
                third_largest = second_largest;
                second_largest = i;
            }
        }
        else if(array[i] < array[second_largest]){
            if(third_largest == -1 || array[third_largest] < array[i]){
                third_largest = i;
            }
        }
    }
    cout << "Three Largest number in this Array is " << array[first_largest] << ", "<<array[second_largest] << ", " << array[third_largest] << endl;

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
    largestThreeElements(array,size_of_Array);    
}