#include<iostream>
using namespace std;
/* Write a C++ program to sum of all positive integers in a sentence.
Sample string: There are 12 chairs, 15 desks, 1 blackboard and 2 fans.
Output: 30 */
int main(){
    string input;
    cout << "enter the string : ";
    getline(cin,input);
    int sum = 0;
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if(isdigit(input[i])){
            temp.push_back(input[i]);
            for(int j = i+1;j<input.length();j++){
                if(j >= input.length()){
                    break;
                }
                else if(isdigit(input[j])){
                    temp.push_back(input[j]);
                    i = j;
                }
                else{
                    break;
                }
            }
            sum += stoi(temp);
            temp.clear();
        }
    }
    cout << "Sum : "<< sum;
    
}