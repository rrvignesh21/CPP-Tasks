#include<iostream>
using namespace std;

class complexnumber
{
private:
    float real;
    float img;
public:
    complexnumber(){

    }
    void getcomplex(){
        cout << "Enter complex number: ";
        cin >> real >> img;
    }
    void printcomp(){
        cout << real << "+i" << img ;
    }
    complexnumber operator + (const complexnumber &obj){
        complexnumber tp;
        tp.real = real + obj.img;
        tp.img = img + obj.img;
        return tp;
    }
};

int main(){
    complexnumber c1,c2,res;
    c1.getcomplex();
    c2.getcomplex();
    res = c1 + c2;
    res.printcomp();
}
