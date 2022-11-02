#include<iostream>
using namespace std;
/*Program to swap two numbers/characters using a function template.*/
template<class T>
void swapVar(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int ia = 10;
    int ib = 20;
    cout <<"number 1 : " << ia << "\n" << "number 2 : " << ib << endl;
    swapVar(ia,ib);
    cout <<"number 1 : " << ia << "\n" << "number 2 : " << ib << endl;
    char ca = 'A';
    char cb = 'B';
    cout <<"char 1 : " << ca << "\n" << "char 2 : " << cb << endl;
    swapVar(ca,cb);
    cout <<"char 1 : " << ca << "\n" << "char 2 : " << cb << endl;

}