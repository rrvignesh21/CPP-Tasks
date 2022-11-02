#include<iostream>
using namespace std;
/* Create a student management application using all levels of inheritance using C++. */
class Subject{
    string subjectName;
    int credit;
    int Mark;
    public:
    void setSubjectName(){
        cin >> this->subjectName;
    }
    void setMark(){
        cin >> this->Mark;
    }
    void setCredit(){
        cin >> this->credit;
    }
    int getMark(){
        return (this->Mark);
    }
    int getCredit(){
        return (this->credit);
    }
    string getSubjectName(){
        return (this->subjectName);
    }
};

class Semester{
    int no_Of_Subjects;
    Subject *subject;
    int TotalMark;
    double gpa;

    public:
    ~Semester(){
        delete this->subject;
    }
    void setSubjectMark(){
        for(int i = 0;i<this->no_Of_Subjects;i++){
            cout << "Enter Subject " << i+1 << " Mark : ";
            this->subject[i].setMark();
        }        
    }
    void setNo_Of_Subject(){
        cin >> no_Of_Subjects;
        subject = new Subject[this->no_Of_Subjects];
        for(int i = 0;i<this->no_Of_Subjects;i++){
            cout << "Enter Subject "<< i+1 <<" Name : ";
            this->subject[i].setSubjectName();
        }
    }
    void setSubjectCredit(){
        for(int i = 0;i<this->no_Of_Subjects;i++){
            cout << "Enter Subject "<< i+1 <<" Credit : ";
            this->subject[i].setCredit();
        }
    }
    double calculateGpa(){
        int total = 0;
        int totalcredit = 0;
        for(int i = 0;i<this->no_Of_Subjects;i++){
            total = total + (((this->subject[i].getMark())/10)*(this->subject[i].getCredit()));
            totalcredit = totalcredit + (this->subject[i].getCredit());
        } 
        this->gpa = total / ((double)totalcredit);
        return (this->gpa);
    }

    int calculateTotalMark(){
        this->TotalMark = 0;
        for(int i = 0;i<this->no_Of_Subjects;i++){
            this->TotalMark = this->TotalMark + this->subject[i].getMark();
        } 
        return (this->TotalMark);
    }
    void getsubjectMarks(){
        for(int i = 0;i<this->no_Of_Subjects;i++){
            cout << this->subject[i].getMark() << endl;
        }
    }
};

class Acadamics{
    int no_of_Semesters;
    Semester *semesters;
    public:
    ~Acadamics(){
        delete this->semesters;
    }
    void setNo_Of_Semesters(){
        cin >> this->no_of_Semesters;
        this->semesters = new Semester[this->no_of_Semesters];
    }
    void setMarks(){
        for(int i = 0;i<this->no_of_Semesters;i++){
            cout << "Enter No Of Subjects in" <<i+1<<" Semester : ";
            this->semesters[i].setNo_Of_Subject();
            this->semesters[i].setSubjectCredit();
            this->semesters[i].setSubjectMark();
        }
    }
    void getSemesterReport(){
        for(int i = 0;i<this->no_of_Semesters;i++){
            cout <<"Semester " << i+1 << endl;
            this->semesters[i].getsubjectMarks();
            cout << "Total Mark : " <<this->semesters[i].calculateTotalMark() << endl;
            cout << "GPA : " << this->semesters[i].calculateGpa() << endl;
        }
    }
};

class Attendence{
    int Total_Working_Days = 230;
    int no_Of_Days_Present;
    double attendencePrecentage;
    public:
    void setNo_Of_Present_Days(){
        cin >> this->no_Of_Days_Present;
    }
    double calculateAttendence_Percentage(){
        this->attendencePrecentage = (this->no_Of_Days_Present /(double)this->Total_Working_Days)*100;
        return this->attendencePrecentage;
    }
};

class Student : public Acadamics,public Attendence{
    protected:
    string studentName;
    string department;
    int current_Year;
    public:
    void setStudentName(){
        cin >> this->studentName;
    }
    void setStudentDepartment(){
        cin >> this->department;
    }  
    void getStudentInfo(){
        cout << "Student Name : " << this->studentName << endl;
        cout << "Department : "<< this->department << endl;
        cout << "current Year : " << this->current_Year << endl;
    }
};

class Fees{
    int tutionfee;
    int foodfee;
    int examfee;
    bool tutionfeestatus;
    bool foodfeestatus;
    int examfeestatus;
    public:
    Fees(){
        this->tutionfeestatus = false;
        this->foodfeestatus = false;
    }
    void settutionfee(int fee){
        this->tutionfee = fee;
    }
    void setfoodfee(int fee){
        this->foodfee = fee;
    }
    int gettutionfee(){
        return(this->tutionfee);
    }
    int getfoodfee(){
        return(this->foodfee);
    }
    void settutionfeestatus(){
        this->tutionfeestatus = true; 
    }
    void setfoodfeestatus(){
        this->foodfeestatus = true;
    }
    bool gettutionfeestatus(){
        return(this->tutionfeestatus);
    }
    bool getfoodfeestatus(){
        return(this->foodfeestatus);
    }
};

class Year_1_Students:public Student,public Fees{
    public:
    Year_1_Students(){
        this-> current_Year = 1;
    }
};
class Year_2_Students:public Student,public Fees{
    public:
    Year_2_Students(){
        this-> current_Year = 2;
    }
};
class Year_3_Students:public Student,public Fees{
    public:
    Year_3_Students(){
        this-> current_Year = 3;
    }
};
class Year_4_Students:public Student{
    public:
    Year_4_Students(){
        this-> current_Year = 4;
    }
};
class StudentRecordManagement{
    int no_of_Students_in_1Year;
    int no_of_Students_in_2Year;
    int no_of_Students_in_3Year;
    int no_of_Students_in_4Year;
    Year_1_Students *student_1_Data;
    Year_2_Students *student_2_Data;
    Year_3_Students *student_3_Data;
    Year_4_Students *student_4_Data;
    public:
    StudentRecordManagement(){
        int fg = 1;
        while (fg){        
        int option;
        cout << "1.Update Student Data \n2.View Studnent Data\n3.Exit"<< endl;
        cin >> option;
        switch (option)
        {
        case 1:
            int suboption;
            cout << "1.Update 1st Year Student Data\n2.Update 2nd Year Student Data\n3.Update 3rd Year Student Data\n4.Update 4th Year Student Data"<<endl;
            cin >> suboption;
            switch (suboption)
            {
            case 1:
                cout << "Enter the number Of student in 1st year : ";
                cin >> this->no_of_Students_in_1Year;
                this->student_1_Data = new Year_1_Students[this->no_of_Students_in_1Year];
                for(int i = 0;i<this->no_of_Students_in_1Year;i++){
                    cout << "Enter Student " << i+1 << " name : ";
                    student_1_Data[i].setStudentName();
                    cout << "Enter Student " << i+1 << " Department : ";
                    student_1_Data[i].setStudentDepartment();
                    cout << "Enter Student " << i+1 << " Attended Days : ";
                    student_1_Data[i].setNo_Of_Present_Days();
                    cout << "Enter the No of Semesters : ";
                    student_1_Data[i].setNo_Of_Semesters();
                    student_1_Data[i].setMarks();

                }  
                break;
            case 2:
                cout << "Enter the number Of student in 2nd year : ";
                cin >> this->no_of_Students_in_2Year;
                this->student_2_Data = new Year_2_Students[this->no_of_Students_in_2Year];
                for(int i = 0;i<this->no_of_Students_in_2Year;i++){
                    cout << "Enter Student " << i+1 << " name : ";
                    student_2_Data[i].setStudentName();
                    cout << "Enter Student " << i+1 << " Department : ";
                    student_2_Data[i].setStudentDepartment();
                    cout << "Enter Student " << i+1 << " Attended Days : ";
                    student_1_Data[i].setNo_Of_Present_Days();
                    cout << "Enter the No of Semesters : ";
                    student_2_Data[i].setNo_Of_Semesters();
                    student_2_Data[i].setMarks();
                }  
                break;
            case 3:
                cout << "Enter the number Of student in 3rd year : ";
                cin >> this->no_of_Students_in_3Year;
                this->student_3_Data = new Year_3_Students[this->no_of_Students_in_3Year];
                for(int i = 0;i<this->no_of_Students_in_3Year;i++){
                    cout << "Enter Student " << i+1 << " name : ";
                    student_3_Data[i].setStudentName();
                    cout << "Enter Student " << i+1 << " Department : ";
                    student_3_Data[i].setStudentDepartment();
                    cout << "Enter Student " << i+1 << " Attended Days : ";
                    student_3_Data[i].setNo_Of_Present_Days();
                    cout << "Enter the No of Semesters : ";
                    student_3_Data[i].setNo_Of_Semesters();
                    student_3_Data[i].setMarks();  
                }
                break;
            case 4:
                cout << "Enter the number Of student in 4th year : ";
                cin >> this->no_of_Students_in_4Year;
                this->student_4_Data = new Year_4_Students[this->no_of_Students_in_4Year];
                for(int i = 0;i<this->no_of_Students_in_4Year;i++){
                    cout << "Enter Student " << i+1 << " name : ";
                    student_4_Data[i].setStudentName();
                    cout << "Enter Student " << i+1 << " Department : ";
                    student_4_Data[i].setStudentDepartment();
                    cout << "Enter Student " << i+1 << " Attended Days : ";
                    student_4_Data[i].setNo_Of_Present_Days();
                    cout << "Enter the No of Semesters : ";
                    student_4_Data[i].setNo_Of_Semesters();
                    student_4_Data[i].setMarks();  

                }
                break;
            default:
                break;
        }  
            break;
        case 2:
            int altOption;
            cout << "1.View 1st Year Student Data\n2.View 2nd Year Student Data\n3.View 3rd Year Student Data\n4.View 4th Year Student Data"<<endl;
            cin >> altOption;
            switch (altOption)
            {
            case 1:
                for(int i = 0;i<this->no_of_Students_in_1Year;i++){
                    this->student_1_Data[i].getStudentInfo();
                    this->student_1_Data[i].getSemesterReport();
                    cout << "Attendence : " << this->student_1_Data[i].calculateAttendence_Percentage() << "%" << endl;
                    
                }
                break;
            case 2:
                for(int i = 0;i<this->no_of_Students_in_2Year;i++){
                    this->student_2_Data[i].getStudentInfo();
                    this->student_2_Data[i].getSemesterReport();
                    cout << "Attendence : " << this->student_2_Data[i].calculateAttendence_Percentage() << "%" << endl;

                }
                break;
            case 3:
                for(int i = 0;i<this->no_of_Students_in_3Year;i++){
                    this->student_3_Data[i].getStudentInfo();
                    this->student_3_Data[i].getSemesterReport();
                    cout << "Attendence : " << this->student_3_Data[i].calculateAttendence_Percentage() << "%"<<endl;
                }
                break;
            case 4:
                for(int i = 0;i<this->no_of_Students_in_4Year;i++){
                    this->student_4_Data[i].getStudentInfo();
                    this->student_4_Data[i].getSemesterReport();
                    cout << "Attendence : " << this->student_4_Data[i].calculateAttendence_Percentage() << "%" <<endl;
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            fg = 0;
            break;
        default:
            break;
        }
    }
}
    ~StudentRecordManagement(){
        delete student_1_Data;
        delete student_2_Data;
        delete student_3_Data;
        delete student_4_Data;
    }

};

int main(){
    StudentRecordManagement studentrecord;   
}