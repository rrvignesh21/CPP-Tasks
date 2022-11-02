#include<iostream>
using namespace std;
/* To search an element from an array by linear search method. */
int linearsearch(int arr[],int n,int num);
int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the Elements : ";
    for(int i = 0 ;i < n;i++){
        cin >> arr[i];
    }
    int num;
    cout << "Enter the number to search : ";
    cin >> num;
    int result = linearsearch(arr,n,num);
    if(result >= 0){
        cout << num << " is in " << result << " index of the array " << endl;
    } 
    else{
        cout << "there is no element matches "<< num << " in this array " << endl;
    }
}

int linearsearch(int arr[],int n,int num){
    for(int i = 0;i < n;i++){
        if(arr[i] == num){
            return i;
        }
        else{
            continue;
        }
    }
    return -1;
}