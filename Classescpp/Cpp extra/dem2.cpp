#include<iostream>
#include<string.h>
using namespace std;
  
class student
{   
    public:
    int rno;
    char name[50];
    double fee;
    public:
    student(int,char[],double);
    student(student &t)       //copy constructor (member wise initialization)
    {
        rno=t.rno;
        strcpy(name,t.name);
        fee = t.fee;          
    }
    void display();
    void disp()
    {
        cout<<endl<<rno<<"\t"<<name;
    }
      
};
    student::student(int no, char n[],double f)
    {
        rno=no;
        strcpy(name,n);
        fee=f;
    }    
  
   void student::display()
    {
        cout<<endl<<rno<<"\t"<<name<<"\t"<<fee;
    }
      
  
  
int main()
{
    student s(1001,"Ram",10000);
    s.display();
      
    student ram(s);   //copy constructor called
    ram.display();
    ram.fee = 1;
    ram.display();
    s.display();         
   return 0;
}