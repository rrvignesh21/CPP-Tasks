#include<iostream>
using namespace std;
/*  Write a c++ program for calculating area of triangle, circles and parallelogram using friend function. */
class Triangle{
    int base,height;
    public:
    Triangle(){
        cout << "Enter Base of Triangle : ";
        cin >> this->base;
        cout << "Enter height of Triangle : ";
        cin >> this->height;
    }
    friend void calculateAreaOfTriangle(Triangle triangle);
};

class Circle{
    int radius;
    public:
    Circle(){
        cout << "Enter Radius of Circle : ";
        cin >> this->radius;
    }
    friend void calculateAreaOfCircle(Circle circle);
};

class Parallelogram{
    int base,height;
    public:
    Parallelogram(){
        cout << "Enter Base of Parallelogram : ";
        cin >> this->base;
        cout << "Enter height of Parallelogram : ";
        cin >> this->height;
    }
    friend void calculateAreaOfParallelogram(Parallelogram parallelogram);
};

void calculateAreaOfTriangle(Triangle triangle){
    cout << "Area of Triangle : " <<(0.5 * triangle.base * triangle.height) << endl;
}

void calculateAreaOfCircle(Circle circle){
    cout << "Area of Circle : " <<(3.15 * circle.radius * circle.radius) << endl;
}

void calculateAreaOfParallelogram(Parallelogram parallelogram){
    cout << "Area of Parallelogram : "<< (parallelogram.base * parallelogram.height) << endl;
}

int main(){
    Circle circle;
    Triangle triangle;
    Parallelogram parallelogram;
    calculateAreaOfCircle(circle);
    calculateAreaOfTriangle(triangle);
    calculateAreaOfParallelogram(parallelogram);
}