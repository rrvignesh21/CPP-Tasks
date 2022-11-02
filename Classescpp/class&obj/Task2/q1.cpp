#include<iostream>
using namespace std;
/* .Write a program to print the names of students by creating a Student class. 
If no name is passed while creating an object of the Student class, then the name should be "Unknown",
 otherwise the name should be equal to the String value passed while creating the object of the Student class. */
class Student{
    int Roll_number;
    string Name;
    public:
    Student(){
        Roll_number = 0;
        Name = "Unknown";
    }
    Student(int Roll_Number,string name){
        Roll_number = Roll_Number;
        Name = name;
    }
    void display(){
        cout << "Roll_Number : "<<Roll_number << endl;
        cout << "Name : "<< Name << endl;
    }
};

int main(){
    Student student1;
    Student student2(23,"Raja");
    student1.display();
    student2.display();
}