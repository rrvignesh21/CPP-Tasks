#include<iostream>
using namespace std;
/* Write a C++ program to overload the binary operator '+' to add two complex numbers. */
class Complex_Number{
    double real,imaginary;
    public:
    void setComplexNumber(){
        cout << "Enter the complex number (real imaginary): ";
        cin >> real >> imaginary;
    }
    Complex_Number operator + (Complex_Number complexnumber){
        Complex_Number result;
        result.real = real + complexnumber.real;
        result.imaginary = imaginary + complexnumber.imaginary;
        return result;
    }
    void display(){
        if(imaginary < 0){
            cout << real << imaginary << "i" <<endl;
        }
        else{
            cout << real << "+" << imaginary << "i" <<endl;
        }
    }
};
int main(){
    Complex_Number complex_number1;
    complex_number1.setComplexNumber();
    Complex_Number complex_number2;
    complex_number2.setComplexNumber();
    Complex_Number result = complex_number1 + complex_number2;
    result.display();
}