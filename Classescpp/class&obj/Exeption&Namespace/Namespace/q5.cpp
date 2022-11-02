#include<iostream>
using namespace std;
/* Illustrate with an example using an inline namespace. */
inline namespace something{
    int number1 = 9334;
}
inline namespace other{
    double db = 12.432;
}

namespace A{
    int number2 = 14;
    inline namespace B{
        int number3 = 12;
    }
}

int main(){
    
    cout << something::number1 << endl;
    cout << db << endl;
    cout << A::number2 << endl;
    cout << A::number3 << endl;
    cout << A::B::number3 << endl;   
}