#include<iostream>
using namespace std;
/* Sort the elements in descending order. */
void printArray(int array[],int size_of_Array){
    for (int i = 0; i < size_of_Array; i++)
    {
        cout << array[i] << " ";
    }
}

void shellSort(int array[],int length){
    for(int gap = length/2;gap > 0;gap /= 2){
        for(int i = gap;i<length;i++){
            int temp = array[i];
            int j;            
            for( j = i;j>=gap && array[j - gap] < temp;j-=gap){
                array[j] = array[j - gap];
            }  
            array[j] = temp;
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
    shellSort(array,size_of_Array);
    printArray(array,size_of_Array);

    
}