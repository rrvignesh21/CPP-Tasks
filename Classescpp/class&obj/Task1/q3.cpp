#include<iostream>
using namespace std;
/* Write a program to print the area and perimeter of a triangle
 having sides of 3, 4 and 5 units by creating a class named 'Triangle' with a function to print the area and perimeter */
class Triangle{
    int base;
    int height;
    int hypotenuse;    
    public:
    Triangle(){
    this->base = 4;
    this->height = 3;
    this->hypotenuse = 5;
    }
    void perimeter(){
        cout << "Perimeter of the triangle : " << (base + height + hypotenuse) << endl;
    }
    void area(){
        cout << "Area of the triangle : " << (0.5*(base*height)) << endl;
    }
};

int main(){
    Triangle triangle;
    triangle.perimeter();
    triangle.area();
}