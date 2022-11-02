#include<iostream>
using namespace std;
/* Find the Sum of two operands with various datatypes using function overloading. */
int sum(int num1,int num2){
    return(num1+num2);
}
double sum(double num1,double num2){
    return (num1+num2);
}
string sum(string a,string b){
     return (a + b);
}


int main(){
    int sumint = sum(3,2);
    double sumfl = sum(3.12 ,2.14);
    string sumch = sum("ab","cd");
    cout << sumint << "  " << sumfl << " "<<sumch;
}