#include<iostream>
#include<vector>
#include<cerrno>
using namespace std;

int main(){
    vector<int> vector1 = {1,2,3,4};
    vector1.push_back(34);

    for(int i : vector1){
        cout << i << " " ;
    }

}