#include<iostream>
using namespace std;
/* Create a class named 'Student' with a string variable 'name' and an integer variable 'roll_no'.
 Assign the value of roll_no as '2' and that of name as "John" by creating an object of the class Student. */
class Student{
    public:
    int roll_number;
    string name;
    void display(){
        cout << "Roll Number : " << roll_number << endl;
        cout << "Name : " << name << endl;
    }
};

int main(){
    Student student;
    student.name = "John";
    student.roll_number = 2;
    student.display();
}