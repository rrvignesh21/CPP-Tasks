#include<iostream>
using namespace std;
/* Assign and print the roll number,
 phone number and address of two students having names "Sam" and "John" respectively by creating two objects of the class 'Student'. */
class Student{
    public:
    int roll_number;
    string name;
    int phone_number;
    string address;
    
    void display(){
        cout << "Roll Number : " << roll_number << endl;
        cout << "Name : " << name << endl;
        cout << "Phone Number : " << phone_number << endl;
        cout << "Address : " << address << "\n" << endl;
    }
};

int main(){
    Student student1;
    Student student2;
    student1.name = "John";
    student2.name = "Sam";
    student1.roll_number = 2;
    student2.roll_number = 3;
    student1.phone_number = 1234566;
    student2.phone_number = 979087;
    student1.address = "Trichy";
    student2.address = "Thoothukodi";
    student1.display();
    student2.display();
}