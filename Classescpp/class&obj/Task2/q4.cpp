#include<iostream>
using namespace std;
/* Create a class named 'Rectangle' with two data members- length and breadth and a function to calculate the area which is 'length*breadth'. The class has three constructors which are :

    1 - having no parameter - values of both length and breadth are assigned zero.

    2 - having two numbers as parameters - the two numbers are assigned as length and    breadth respectively.

     3 - having one number as parameter - both length and breadth are assigned that number.

Now, create objects of the 'Rectangle' class having none, one and two parameters and print their areas. */
class Rectangle{
    int breadth,width;
    public:
    Rectangle(){
        breadth = 0;
        width = 0;
    }

    Rectangle(int Pbreadth,int Pwidth){
        breadth = Pbreadth;
        width = Pwidth;
    }
    Rectangle(int length){
        breadth = length;
        width = length;
    }

    void Area(){
        cout << "Area of the Rectangle with breadth "<< breadth << " and width "<< width << " is " <<(breadth * width) << endl;
    }
};

int main(){
    Rectangle rectangle1;
    Rectangle rectangle2(5,2);
    Rectangle rectangle3(10);
    rectangle1.Area();
    rectangle2.Area();
    rectangle3.Area();
}