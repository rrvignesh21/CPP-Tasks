#include<iostream>
using namespace std;
/* Print the sum, difference and product of two complex numbers by creating a class named 
'Complex' with separate functions for each operation whose real and imaginary parts are entered by the user. */
class ComplexNumber{
    double real_part,imaginary_part;
    public:
    void setComplex_number(){
        cout << "Enter the Complex Number : ";
        cin >> real_part >>imaginary_part;
    }
    void add(ComplexNumber complex){
        if((imaginary_part + complex.imaginary_part) < 0){
        cout << (real_part + complex.real_part) <<(imaginary_part + complex.imaginary_part) << "i" << endl; 
        }
        cout << (real_part + complex.real_part) << "+" << (imaginary_part + complex.imaginary_part) << "i" << endl; 
    }
    void multiply(ComplexNumber complex){
        double real = (real_part*complex.real_part) - (imaginary_part * complex.imaginary_part);
        double imaginary = (real_part*complex.real_part) + (imaginary_part * complex.imaginary_part);
        if(imaginary < 0){
        cout << real << imaginary << "i" << endl; 
        }
        else{
        cout << real << "+" << imaginary << "i" << endl; 
        }
}
    void difference(ComplexNumber complex){
        if((imaginary_part - complex.imaginary_part) < 0){
        cout << (real_part - complex.real_part) << (imaginary_part - complex.imaginary_part) << "i" << endl; 
        }
        else{
        cout << (real_part - complex.real_part) << "+" << (imaginary_part - complex.imaginary_part) << "i" << endl; 
        }
    }
};
int main(){
    ComplexNumber complex_number1;
    ComplexNumber complex_number2;
    complex_number1.setComplex_number();
    complex_number2.setComplex_number();
    cout << "Sum of complex Number : ";
    complex_number1.add(complex_number2);
    cout << "Difference of complex Number : ";
    complex_number1.difference(complex_number2);
    cout << "Product of complex Number : ";
    complex_number1.multiply(complex_number2);
}