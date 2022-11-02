#include<iostream>
using namespace std;
/* Program to create alias name for the namespace. */
namespace first{
    namespace second
    {
        int num = 12;
        namespace third{
            int number = 101;
            string str = "hello";
        }
    }
}
namespace finalname = first::second::third;

int main(){
    cout << first::second::third::number << endl;
    cout << first::second::third::str << endl;
    cout << "Using alias name" << endl;
    cout << finalname::number << endl;
    cout << finalname::str << endl;
}
