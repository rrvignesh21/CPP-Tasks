#include<iostream>
using namespace std;
/* Write a program which will ask the user to enter his/her marks (out of 100). Define a function that will display grades according to the marks entered as below:
Marks        Grade
91-100         AA
81-90          AB
71-80          BB
61-70          BC
51-60          CD
41-50          DD
<=40          Fail
 */
void grades(int marks[],int number_of_subjects);
int main(){
    int number_of_subjects;
    cout << "Enter Number of subjects: ";
    cin >> number_of_subjects;
    int marks[number_of_subjects];
    cout << "Enter marks : ";
    for(int i = 0;i < number_of_subjects;i++){
        cin >> marks[i];
    }
    grades(marks,number_of_subjects);
}

void grades(int marks[],int number_of_subjects){
    for(int i = 0;i < number_of_subjects;i++){
        if(marks[i] >= 91 && marks[i] <= 100){
            cout << marks[i] << "-----" << "AA" << endl;
        } 
        if(marks[i] >= 81 && marks[i] <= 90){
            cout << marks[i] << "-----" << "AB" << endl;
        }
        if(marks[i] >= 71 && marks[i] <= 80){
            cout << marks[i] << "-----" << "BB" << endl;
        }
        if(marks[i] >= 61 && marks[i] <= 70){
            cout << marks[i] << "-----" << "BC" << endl;
        }
        if(marks[i] >= 51 && marks[i] <= 60){
            cout << marks[i] << "-----" << "CD" << endl;
        }
        if(marks[i] >= 41 && marks[i] <= 50){
            cout << marks[i] << "-----" << "DD" << endl;
        }
        if(marks[i] <= 40){
            cout << marks[i] << "-----" << "Fail" << endl;
        }
    }
}