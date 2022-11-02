#include<iostream>
using namespace std;
/* Write a code to use fully-qualified namespaces. */
namespace Student1{
    int id;
    string name;
}
namespace Student2{
    int id;
    string name;
}
int main(){
    cout <<"Enter Student 1 id : ";
    cin >> Student1::id;
    cout << "Enter Student 1 name : ";
    cin >> Student1::name;
    cout <<"Enter Student 2 id : ";
    cin >> Student2::id;
    cout << "Enter Student 2 name : ";
    cin >> Student2::name;
    cout << "Student 1 Id : " << Student1::id << endl;
    cout << "Student 1 Name : "<< Student1::name << endl;
    cout << "\nStudent 2 Id : " << Student2::id << endl;
    cout << "Student 2 Name : "<< Student2::name << endl;
    
}