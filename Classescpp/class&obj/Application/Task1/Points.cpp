#include<iostream>
using namespace std;
/* A class Point is declared as follows:

class Point{

public:

Point(int=0;int=0);  //default constructor

void setPoint(int,int); //set coordinates

int getX() const {return x;} //get x coordinates

int getY() const {return y;} //get y coordinates

void printPoint(); // print (x,y) coordinates

private:

int x,y;

};

Write the implementation of the class Point in the same file.

Then, declare a class called Circle that is derived from the class Point. The class Circle has public member functions Circle (constructor), setRadius(), getRadius() and area() and one private data member radius. The class Circle indirectly uses private member x and y of class Point to store the coordinate of the center of the circle. The class Circle also checks to make sure the radius value is a positive number, otherwise it is set to default value 1.

Note: The private members of class Point can only be indirectly accessed by class Circle using public methods of class point.

Implement the class Circle and write a driver program to test the class Circle. An example of the output of the driver program is.

Enter x: 2

Enter y: 2

Enter radius: 1

Circle center is (2,2)

Radius is 1

Area is 3.14 */
class Point{

public:

Point(){
    this->x = 0;
    this->y = 0;
}   //default constructor

void setPoint(int x,int y){
    this->x = x;
    this->y = y;
} //set coordinates

int getX() const {return x;} //get x coordinates

int getY() const {return y;} //get y coordinates

void printPoint(){
    cout << "X = "<<this->x << endl;
    cout << "Y = " << this->y << endl;
} // print (x,y) coordinates

private:

int x,y;

};

class Circle:public Point{
    int radius;
    public:
    Circle(){
       this->radius = 1; 
    }
    void setRadius(){
        cout << "Enter Radius : ";
        cin >> this->radius;
        if(this->radius < 0){
            this->radius = 1;
        }
    }
    void getRadius(){
        cout << "Radius = " << this->radius << endl;
    }
    void area(){
        cout << "Area = " << (3.14 * (this->radius) * (this->radius)) << endl;
    }
};

int main(){
    Circle circle;
    cout << "Enter X : ";
    int x;
    cin >> x;
    cout << "Enter Y : ";
    int y;
    cin >> y;
    circle.setPoint(x,y);
    circle.setRadius();
    cout << "Circle centre is (" <<circle.getX() << "," << circle.getY() << ")" << endl;
    circle.getRadius();
    circle.area(); 
}
