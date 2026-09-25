#include<iostream>
#include<string>
using namespace std;
class Employee{
    protected:
    int id;
    string name;
    string dept;
    float netsalary;
    public :
    void getdata(){
        cout<<"Enter employee id:";
        cin>>id;
        cout<<"\n Enter employee name:";
        cin>>name;
        cout<<"\n Enter department name:";
        cin>>dept;

    }
    virtual void calculate_salary(){
        cout<<"Netsalary: ";

    }
    void displaydata(){
        cout<<"Employee id:"<<id;
        cout<<"\n Employee name:"<<name;
        cout<<"\n Employee's department name:"<<dept;
        
        
    }
};

class permanent:public Employee{

    public :
    float basic_salary;
    void calculate_salary(){
        cout<<"\n Enter basic salary:";
        cin>>basic_salary;
        netsalary=basic_salary+(0.1*basic_salary);
        displaydata();
        cout<<"\n netsalary:"<<netsalary;
        


    }

};

class contract:public Employee{

    public :
    float basic_salary;
    int overtime_hrs;
    void calculate_salary(){
        cout<<"\n Enter basic salary:";
        cin>>basic_salary;
        cout<<"Enter overtime hours:";
        cin>>overtime_hrs;
        netsalary=basic_salary+(overtime_hrs*200);
        displaydata();
        cout<<"\n netsalary:"<<netsalary;
        


    }

};
int main(){
    Employee *emp;
    permanent p;
    contract c;
    int choice;
    cout<<"1.Permanent 2.Contract ";
    cout<<"Enter choice:";
    cin>>choice;
    switch(choice){
        case 1: emp=&p;
            break;
        case 2:emp=&c;
            break;
        default:
            cout<<"Invalid choice";
    }
    emp->getdata();
    emp->displaydata();
    emp->calculate_salary();
}