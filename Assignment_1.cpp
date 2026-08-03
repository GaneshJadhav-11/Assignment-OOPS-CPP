#include<iostream>
#include<string.h>
using namespace std;
string company ="scoe";
enum dept{
    it,
    finance,
    sales,
    hr
};
inline float calculateBonus(float basicsalary,int attendancedays){
    if(attendancedays>=26){
        return basicsalary*0.1;
      
    }
    else{
        return basicsalary*0.05;
    }
}
float overtimepay(float overtimehrs){
    return overtimehrs*1000;
}
float basicsalary(int attendancedays, float perday){
    return attendancedays*perday;
}

void calculatenetsalary(float &netsalary,float basicsalary,float bonus,float overtimepay,float leavededuction){
    netsalary=basicsalary+bonus+overtimepay-leavededuction;
}
int main(){
    int n;
    cout<<"company name:"<<::company<<endl;
    cout<<"Enter number of employees";
    cin>>n;
    int empid[50];
    string empname[50];
    int attendancedays[50];
    float perdaysalary[50];
    float overtimehrs[50];

    for(int i=0;i<n;i++){
        cout<<"employee"<<i+1<<"details"<<endl;
        cout<<"Enter employee id:";
        cin>>empid[i];
        cout<<"Enter employee name:"<<endl;
        cin>>empname[i];
        cout<<"Attendance days:"<<endl;
        cin>>attendancedays[i];
        cout<<"Enter per day salary"<<endl;
        cin>>perdaysalary[i];
        cout<<"Enter overtime hrs:"<<endl;
        cin>>overtimehrs[i];
    }
    cout<<"Payroll report"<<endl;
    for(int i=0;i<n;i++){
        float basicsalary;
        float bonus;
        float overtime;
        float leavededuction;
        float netsalary;
        basicsalary=attendancedays[i]*perdaysalary[i];
        overtime=overtimepay(overtimehrs[i]);
        bonus = calculateBonus(basicsalary,attendancedays[i]);
        leavededuction=(30-attendancedays[i])* perdaysalary[i];
        calculatenetsalary(netsalary,basicsalary,overtime,bonus,leavededuction);
        {
        cout<<"Enter employee id:"<<empid[i]<<endl;
        cout<<"Enter employee name:"<<empname[i]<<endl;;
        cout<<"Attendance days:"<<attendancedays[i]<<endl;
        cout<<"Enter per day salary"<<perdaysalary[i]<<endl;
        cout<<"Enter overtime hrs:"<<overtimehrs[i]<<endl;
        cout<<"Net salary"<<netsalary<<endl;
        }
    }
    return 0;
}






// int main(){
//     int work_days,leave_days,salary,perday_salary,bonus;
//     do{
//         cout<<"enter working days"<<endl;
//         cin>>work_days;
//          cout<<"enter leave days"<<endl;
//         cin>>leave_days;
//         cout<<"Enter per day salary:"<<endl;
//         cin>>perday_salary;
//         cout<<"enter bonus"<<endl;
//         cin>>bonus;
//         salary=work_days*perday_salary-(leave_days*perday_salary)+bonus;
//         cout<<"Salary is:"<<salary<<endl;

//         cout<<"Do you wish to continue if yes press 1 else press 0"<<endl;

//     }
    
// }