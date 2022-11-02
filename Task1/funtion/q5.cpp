#include<iostream>
using namespace std;
/* Write a function named "reduce" that takes two positive integer arguments,
 call them "num" and "denom", treats them as the numerator and denominator of a fraction, and reduces the fraction. 
 That is to say, each of the two arguments will be modified by dividing it by the greatest common divisor of the two integers.
  The function should return the value 0 (to indicate failure to reduce) if either of the two arguments is zero or negative, and should return the value 1 otherwise. 
  Thus, for example, if m and n have been declared to be integer variables in a program, then m = 25; n = 15;
   if (reduce(m,n)) cout << m << '/' << n << endl; else cout << "fraction error" << endl;
    will produce the following output: 5/3 Note that the values of m and n were modified by the function call. Similarly, m = 63; n = 210;
 if (reduce(m,n)) cout << m << '/' << n << endl; else cout << "fraction error" << endl; */
int reduce(int num,int denom);

int main(){
    int num,denom;
    cout << "Enter numerator and denominator : ";
    cin >> num >> denom;
    int result = reduce(num,denom);
    if(result > 0){
        cout << num/result << "/" << denom/result << endl;
    }
    else{
        cout << "fraction error" << endl;
    }
}

int reduce(int num,int denom){
    if(num <= 0 || denom <= 0){
        return 0;
    }
    else{
        int result = min(num,denom);
        while (result > 0)
        {
            if(num % result == 0 && denom % result == 0){
                break;
            }
            result--;
        }
        return result;
    }
}