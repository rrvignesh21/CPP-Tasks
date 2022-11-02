#include<iostream>
using namespace std;
/* To find the second largest number. */
int second_largest(int arr[],int n);
int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the Elements : ";
    for(int i = 0 ;i < n;i++){
        cin >> arr[i];
    }
    cout << "Second largest : " << arr[second_largest(arr,n)] << endl;
}

int second_largest(int arr[],int n)
{   
    int first_largest = 0,second_largest = -1;
    for(int i = 1;i < n;i++){
        if(arr[i] > arr[first_largest]){
            second_largest = first_largest;
            first_largest = i;
        }
        else if(arr[i] < arr[first_largest]){
            if(second_largest == -1 | arr[second_largest] < arr[i]){
                second_largest = i;
            }
        }
    }
    return second_largest;
}
