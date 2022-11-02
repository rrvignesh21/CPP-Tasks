#include<iostream>
using namespace std;
/*Write a function template that takes a single type parameter (T) and accepts four function arguments: 
an array of T, a start index, a stop index (inclusive), and an optional initial value.
 The function returns the sum of all the array elements in the specified range and the initial value.*/
template<class T>
T sumOfArray(T arr[],int start,int stop, T init = T()){
    T Total = init;
    for(int i = start;i<=stop;i++){
        Total += arr[i];
    }
    return Total;
}

int main(){
    int iarr[] = {1,2,3,4,5,6,7};
    int Itotal = sumOfArray(iarr,2,5,0);
    double darr[] = {1.23,2.42,5.34,7.56,9.76,7.56};
    double Dtotal = sumOfArray(darr,0,4);
    cout << Itotal << endl;
    cout << Dtotal << endl;
}