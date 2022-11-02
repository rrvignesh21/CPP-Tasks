#include<iostream>
using namespace std;
/*Program to do the arithmetic operations using a class template.*/
template<class T>
class ArithmetricOperation{
    T a;
    T b;
    public:
    ArithmetricOperation(T value1,T value2){
        a = value1;
        b = value2;        
    }
    T add(){
        return(a + b);
    }
    T subtract(){
        return(a - b);
    }
    T multiply(){
        return(a * b);
    }
    T divide(){
        return (a / b);
    }

};

int main(){

    int a = 12;
    int b = 2;
    double adb = 12.34;
    double bdb = 3.212;
    // cout << "Enter integer : ";
    // cin >> a >> b;
    // cout << "Enter double : ";
    // cin >> adb >> adb;
    ArithmetricOperation<int> operations(a,b);
    ArithmetricOperation<double> dboperations(adb,bdb);
    // operations.setValues(a,b);
    // dboperations.setValues(adb,bdb);
    cout << "Addition : "<<operations.add() << endl;
    cout << "Subtraction : "<< operations.subtract() << endl;
    cout << "Divide : " << operations.divide() << endl;
    cout << "multipication : "<< operations.multiply() << endl;
    // cout << "Remainder : "<< operations.reminder() << endl;
    cout << "\n DOUBLE \n";
    cout << "Addition : "<< dboperations.add() << endl;
    cout << "Subtraction : "<< dboperations.subtract() << endl;
    cout << "Divide : " << dboperations.divide() << endl;
    cout << "multipication : "<< dboperations.multiply() << endl;
    // cout << "Remainder : "<< dboperations.reminder() << endl;
}