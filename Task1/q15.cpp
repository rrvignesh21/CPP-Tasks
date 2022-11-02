#include<iostream>
using namespace std;
/* Write a C++ program to check whether the sequence of the numbers in a given array is a "Arithmetic" or "Geometric" sequence. Return -1 if the sequence is not "Arithmetic" or "Geometric".  In mathematics, an arithmetic progression (AP) or arithmetic sequence is a sequence of numbers such that the difference between the consecutive terms is constant. The difference here means the second minus the first. For instance, the sequence 5, 7, 9, 11, 13, 15, . . . is an arithmetic progression with common difference of 2.
In mathematics, a geometric progression, also known as a geometric sequence, is a sequence of numbers where each term after the first is found by multiplying the previous one by a fixed, non-zero number called the common ratio. For example, the sequence 2, 6, 18, 54, ... is a geometric progression with common ratio 3. Similarly 10, 5, 2.5, 1.25, ... is a geometric sequence with common ratio 1/2.
Example:
Sample Input: int nums1[] = { 1, 3, 5, 7 }
Sample Output: Arithmetic sequence */
int isgeometric(int arr[],int n);
int isaritmetric(int arr[],int n);
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int aritmetic = isaritmetric(arr,n);
    int geometric = isgeometric(arr,n);
    if(aritmetic == 1){
        cout << "Arithmetric sequence";
    }
    else if(geometric == 1){
        cout << "Geometric sequence";
    }
    else{
        cout << "It is not arithmetric or geometric sequence.";
    }
}

int isaritmetric(int arr[],int n){
    int common_difference = arr[1] - arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if((arr[i + 1] - arr[i]) != common_difference){
            return -1;
        }
        else{
            continue;
        }
    }
    return 1;
}

int isgeometric(int arr[],int n){
    int common_ratio = arr[1] / arr[0];
    for(int i = 0;i<n - 1;i++){
        if((arr[i + 1] / arr[i]) != common_ratio){
            return -1;
        }
        else{
            continue;
        }
    }
    return 1;
}