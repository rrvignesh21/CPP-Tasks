#include<iostream>
using namespace std;
/* Consider the following class Numbersclass Numbers
{
        int x,y,z;
        public:
                // methods
};
Overload the operator unary minus (-) to negate the numbers. */
class Numbers
{
        int x,y,z;
        public:
        void getNumbers(){
            cout << "Enter value x : ";
            cin >> x;
            cout << "Enter value y : ";
            cin >> y;            
            cout << "Enter value z : ";
            cin >> z;
        }
        void operator - (){
            x = -x;
            y = -y;
            z = -z; 
        }
        void displayNumbers(){
            cout << "x = "<< x <<endl;
            cout << "y = "<< y <<endl;
            cout << "z = "<< z <<endl;
        }
};


int main(){
    Numbers numbers;
    numbers.getNumbers();
    cout << "Before Negating : " << endl;
    numbers.displayNumbers();
    -numbers;
    cout << "After Negating : "<< endl;
    numbers.displayNumbers();   
}