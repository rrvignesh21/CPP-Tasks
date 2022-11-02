#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream File("sometxt.txt",ios::app);
    cout << "Enter the data to be append : ";
    string appendData;
    getline(cin,appendData);
    File << appendData;
    File.close();
}