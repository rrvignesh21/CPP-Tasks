#include<iostream>
using namespace std;
/* Create a class named 'Programming'.
 While creating an object of the class, if nothing is passed to it, then the message "I love programming languages" should be printed. If some String is passed to it, then in place of "programming languages" the name of that String variable should be printed.

For example, while creating the object if we pass "cpp", then "I love cpp" should be printed. */
class Programming{

    public:
    Programming(){
        cout << "I Love Programming" << endl;
    }
    Programming(string string1){
        cout << "I Love " << string1 << endl;
    }
    ~Programming(){
        
    }
};

int main(){
    Programming program1;
    string input;
    cout << "Enter a String : ";
    cin >> input;
    Programming program2(input);
}