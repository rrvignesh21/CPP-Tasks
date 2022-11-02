#include<iostream>
using namespace std;
/* Illustrate with an example using the same print(). */
namespace print1{
    void print(){
        int number;
        cout << "Enter a number : ";
        cin >> number;
        cout << number << endl;
    }
}
namespace print2{
    void print(){
        string str;
        cin.ignore();
        cout << "Enter a string : ";
        getline(cin,str);
        cout << str << endl;
    }
}

int main(){
    print1::print();
    print2::print();
}
