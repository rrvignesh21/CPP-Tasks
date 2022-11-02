#include<iostream>
using namespace std;
/* To perform addition of two matrix. */
int main(){
    int row,column;
    cout << "Enter rows : ";
    cin >> row;
    cout << "Enter colunm : ";
    cin >> column;
    int arr1[row][column];
    int arr2[row][column];
    int result[row][column];
    cout << "Enter matrix 1 : \n";
    for(int i = 0;i<row;i++){
        for(int j = 0;j<column;j++){
            cin >> arr1[i][j];
        }
    }
    cout << "Enter matrix 2 : \n";
    for(int i = 0;i<row;i++){
        for(int j = 0;j<column;j++){
            cin >> arr2[i][j];
        }
    }
    for(int i = 0;i<row;i++){
        for(int j = 0;j<column;j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    for(int i = 0;i<row;i++){
        for(int j = 0;j<column;j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

}