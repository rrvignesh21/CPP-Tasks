#include<iostream>
using namespace std;
/* .Class Matrix
{
        int a[3][3];
    Public:
        //methods;
};Let m1 and m2 are two matrices. Find out m3=m1+m2 (use operator overloading */

class Matrix{
    int matrix[3][3];
    public:
    void getMatrix(){
        cout << "Enter matrix value(3 x 3) : " << endl;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                cin >> matrix[i][j];
            }
        }
    }
    Matrix operator + (Matrix matrix_2){
        Matrix result;
        for(int i = 0;i<3;i++){
            for(int j = 0;j < 3;j++){
                result.matrix[i][j] = matrix[i][j] + matrix_2.matrix[i][j];
            }
        }
        return result;
    }
    void displayMatrix(){
        cout << "Enter matrix value(3 x 3) : " << endl;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    Matrix matrix_1,matrix_2,result_matrix;
    cout << "Enter value for matrix 1 : "<<endl;
    matrix_1.getMatrix();
    cout << "Enter value for matrix 2 : "<<endl;
    matrix_2.getMatrix();
    result_matrix = matrix_1 + matrix_2;
    result_matrix.displayMatrix();
}