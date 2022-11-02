#include<iostream>
using namespace std;
/* Write a function named "digit_name" that takes an integer argument in the range from 1 to 9, inclusive, and
 prints the English name for that integer on the computer screen. No newline character should be sent to the screen following the digit name. The function should not return a value. The cursor should remain on the same line as the name that has been printed. If the argument is not in the required range, then the function should print "digit error" without the quotation marks but followed by the newline character. Thus, for example, the statement digit_name(7); should print seven on the screen; the statement digit_name(0);
 should print digit error on the screen and place the cursor at the beginning of the next line. */
void digit_name(int number);
int main(){
    int number;
    int fg = 1;
    while(fg){
        cin >> number;
        if(number == 110){
            fg = 0;
        }
        else{
        digit_name(number);
        }
    }    
}

void digit_name(int number){
    if(number >= 1 && number <= 9){
        if(number == 1){
            cout << "One";
        }
        if(number == 2){
            cout << "Two";
        }
        if(number == 3){
            cout << "Three";
        }
        if(number == 4){
            cout << "Four";
        }
        if(number == 5){
            cout << "Five";
        }
        if(number == 6){
            cout << "Six";
        }
        if(number == 7){
            cout << "Seven";
        }
        if(number == 8){
            cout << "Eigit";
        }
        if(number == 9){
            cout << "Nine";
        }
    }
    else
    {   
        cout << "digit error" << endl;
    }
}