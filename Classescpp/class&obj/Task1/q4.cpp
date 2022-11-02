#include<iostream>
using namespace std;
/*  Write a program to print the area of a rectangle by creating a class named 'Area' having two functions.
 First function named as 'setDim' takes the length and breadth of the rectangle as parameters and the second function named as 'getArea' returns the area of the rectangle. 
The length and breadth of the rectangle are entered through the keyboard. */
class Area{
    int breadth,width;
    public:
    void setDim(int ibreadth,int iwidth){
       this->breadth = ibreadth;
       this->width = iwidth;
    } 
    int getArea(){
        return (breadth * width);
    }
};

int main(){
    Area rectangle;
    int width,breadth;
    cout << "Enter Widht of rectangle : ";
    cin >> width;
    cout << "Entet Breadth of rectangle : ";
    cin >> breadth;
    rectangle.setDim(breadth,width);
    int area = rectangle.getArea();
    cout << "Area of given rectangle is "<< area << endl;
}