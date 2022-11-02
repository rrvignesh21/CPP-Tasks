#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream inputFile("input.txt");
    ofstream tempFile("tempfile.txt",ios::app);
    string wordtoBeFound;
    cout << "Enter the word : ";
    cin >> wordtoBeFound;
    string replacingString;
    cout << "Enter the replacing word : ";
    cin >> replacingString;
    string bufferString;
    while(inputFile >> bufferString){
        if(wordtoBeFound == bufferString){
            tempFile << replacingString;            
        }
        else{
            tempFile << bufferString;
        }
        tempFile << ' ';
    }
    tempFile.close();
    inputFile.close();
    remove("input.txt");
    rename("tempfile.txt","input.txt");
}