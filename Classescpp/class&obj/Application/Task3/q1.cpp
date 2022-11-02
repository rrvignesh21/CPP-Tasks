#include<iostream>
using namespace std;
/* In an IT corporation management finance manager wants to 
calculate the salary for all the other departments but he facing problems for getting some details in sales department
 write a c++ program by using encapsulation concept to accept the sales department members count and credit the respective salary. */
class Employee{
    protected:
    int employee_Id;
    string employee_Name;
    string employee_Department;
    int employee_Salary;
    virtual void setEmployeeName() = 0;
    virtual void setEmployeeId(int id) = 0;
    virtual void getEmployeeInfo() = 0;
    virtual void setSalary() = 0;
};

class SalesDepartmentEmployee : public Employee{
    public:
    SalesDepartmentEmployee(){
        this->employee_Department = "Sales Department";
    }
    void setEmployeeName(){
        cin >> this->employee_Name;
    }
    void setEmployeeId(int id){
        this->employee_Id = id;
    }
    void getEmployeeInfo(){
        cout << "Employee Name : " << this->employee_Name << endl;
        cout << "Employee Id : " << this->employee_Id << endl;
        cout << "Employee Department : " << this->employee_Department << endl;
        cout << "Employee Salary : " << this->employee_Salary << endl;
    }
    string getEmployeeName(){
        return (this->employee_Name);
    }
    int getEmployeeId(){
        return (this->employee_Id);
    }

    void setSalary(){
        cin >> this->employee_Salary;
    }
};

class SalesDepartment{
    int No_Of_Employees;
    SalesDepartmentEmployee *employee;
    public:
    SalesDepartment(){
        cout << "Enter the Number Of Employees in Sales Department : ";
        cin >> this->No_Of_Employees;
        this->employee = new SalesDepartmentEmployee[this->No_Of_Employees];
    }
    ~SalesDepartment(){
        delete this->employee;
    }
    void setSalesEmployeesinfo(){
        for(int i = 0;i<this->No_Of_Employees;i++){
            cout << "Enter Employee " << i+1 << " Name : " << endl;
            this->employee[i].setEmployeeName();
            this->employee[i].setEmployeeId(i+1);
        }
    }

    void creditSalary(){
        cout << " Salary Credit " << endl;
        for(int i = 0;i < this->No_Of_Employees;i++){
            cout << "Enter Salary of " << this->employee[i].getEmployeeName() << " [Id: "<<this->employee[i].getEmployeeId() << "] : ";
            this->employee[i].setSalary();
        }
    }

    void EmployeeesInfo(){
        for(int i = 0;i < this->No_Of_Employees;i++){
            cout << "--------------------------------------------------------\n";
            this->employee[i].getEmployeeInfo();
        }
    }
};

class FinanceManager{
    public:
    void creditSalaryToSalesDepartment(){
        SalesDepartment salesdepartment;
        salesdepartment.setSalesEmployeesinfo();
        salesdepartment.creditSalary();
        cout << "Display Sales Department employee details[Y/N] : " << endl;
        string display;
        cin.ignore();
        getline(cin,display);
        if(display == "Y"){
            salesdepartment.EmployeeesInfo();
        }   
    }
};

int main(){
    FinanceManager manager;
    int choice;
    cout << "1.To Credit salary to Sales Department employees" << endl;
    cin >> choice; 
    if(choice == 1){
    manager.creditSalaryToSalesDepartment();
    }
}