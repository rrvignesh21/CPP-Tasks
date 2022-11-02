#include<iostream>
#include<string>
using namespace std;
/*Program to sum up all the numbers or characters (stored as string) using a function template.*/
template<class T,class N>
N sumOf(T str,N length,N init = N()){
    N total = init;
    for(int i = 0;i<length;i++){
        if(isdigit(str[i])){
            total += (int)str[i] - 48;
        }
        else{
        total += (N)str[i];
        }
    }
    return total;
}

int main(){
    string string1;
    cout << "Enter the string : ";
    cin >> string1;
    int length = string1.length();
    int sum = sumOf(string1,length,0);
    cout << sum << endl;
}