#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream inputNumberFile("Number.txt");
    char buffer;
    ofstream oddFile("Odd.txt");
    ofstream evenFile("Even.txt");
    while(inputNumberFile.get(buffer)){
        if(((buffer - 48) % 2) == 0){
            evenFile << buffer;
        }
        else{
            oddFile << buffer;
        }
    }
    inputNumberFile.close();
    oddFile.close();
    evenFile.close();
}