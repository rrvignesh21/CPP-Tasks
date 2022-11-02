#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream inputFile("inputFile2.txt");
    ofstream tempFile("Temp.txt",ios::app);
    int lineNumber;
    cout << "Which line do you want to remove? : ";
    cin >> lineNumber;
    int lineCount = 1;
    string bufferString;
    while (getline(inputFile,bufferString))
    {
        if(lineCount == lineNumber){
            lineCount++;
            continue;
        }
        else{
            tempFile << bufferString;
        }
        tempFile << "\n";
        lineCount++;
    }
    inputFile.close();
    tempFile.close();
    remove("inputFile2.txt");
    rename("Temp.txt","inputFile2.txt");
    
}