#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string fileName;
    cout << "Enter the fileName : ";
    cin >> fileName;
    ofstream File(fileName);
    cin.ignore();
    string fileContent;
    cout << "Enter the File Content : \n";
    getline(cin,fileContent);
    File << fileContent;
    File.close();
}