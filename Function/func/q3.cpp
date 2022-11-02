#include<iostream>
using namespace std;
/* C++ Program to Add Two Time Objects using call by address */
class Time{
    public:
    int sec,minute,hour;
    void getTime(){
        cout << "Enter the time : ";
        cin >> hour >> minute >> sec;
    }
    void displayTime(){
        cout << hour << ":" << minute << ":" << sec <<endl;
    }
    Time sum_of_Times(Time &time1,Time &time2){
        Time result;
        result.sec = time1.sec + time2.sec;
        result.minute = result.sec / 60;
        result.sec = result.sec % 60;
        result.minute = result.minute + time1.minute + time2.minute;
        result.hour = result.minute / 60;
        result.minute = result.minute % 60;
        result.hour = result.hour + time1.hour + time2.hour;
        return result; 
    }
};
int main(){
    Time time1,time2;
    cout << "Enter time1 [hour minute second] : ";
    time1.getTime();
    cout << "Enter time2 [hour minute second] : ";
    time2.getTime();
    Time sum_of_TIme;
    sum_of_TIme = time1.sum_of_Times(time1,time2);
    sum_of_TIme.displayTime();
}