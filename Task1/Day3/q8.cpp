#include<iostream>
using namespace std;
/* Use call by reference to print character for 8 times(change the formal argument by adding 3),
 actual argument value is 5. Also show up the reference variable value after changing the value, in main(). */
void function(int &n);

int main(){
    int n = 5;
    function(n);
    cout << "   lst : " << n;
}

void function(int &n){
    n = n + 3;
    for(int i = 0;i < n;i++){
    cout << "*" << endl;
    }
}
