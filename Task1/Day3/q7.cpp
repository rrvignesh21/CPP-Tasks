#include<iostream>
using namespace std;
/* Use function pointer to find the following
1. Cube of a number
2. Power of a number x^n */
int cube(int n);
int power (int num,int exp);

int main(){
    int num;
    int exp;
    cin >> num >> exp;
    int (* cuberes) (int) = &cube;
    int cube = cuberes(num);
    int (*powerres) (int,int) = &power;
    int pow = powerres(num,exp);
    cout << "cube of "<< num<< " : " << cube << endl;
    cout << "power : "<< pow << endl;
}

int cube(int n){
    return (n*n*n);
}

int power(int num,int exp){
    int result = 1;
    for(int i = 0;i < exp;i++){
        result *= num;
    }
    return result;
}
