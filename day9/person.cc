#include<stdio.h>
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class person
{
public:
    person()
    :_name("")
    ,_age(0)
    {cout<<"person default create"<<endl;}
    person(string name,int age)
    :_name(name)
    ,_age(age)
    {cout<<"person(string ,int) default create"<<endl;}
    void displayp()
    {cout<<"name:"<<_name<<",age:"<<_age<<endl;}
private:
    string _name;
    int _age;
};



class employee
: public person
{
public:
    employee(string name,int age,long salary,string department)
    :person(name,age)
    ,_salary(salary)
    ,_department(department)
    {cout<<"employee (....)default create"<<endl;}

    void displaye()
    {
        displayp();
        cout<<"salary:"<<_salary<<",department:"<<_department<<endl;
    }
    long getSalary()
    {return _salary;}
private:
    long _salary;
    string _department;
};
void test()
{
    person p1;
    p1.displayp();
    person p2("xiongda",20);
    p2.displayp();

    employee e1("xiongda",20,10000,"sale");
    employee e2("xionger",30,20000,"artificial intellegence");
    employee e3("xiongsan",40,30000,"make PPT");
    
    e1.displaye();
    e2.displaye();
    e3.displaye();

    cout<<"averenge salary: "<<(e1.getSalary()+e2.getSalary()+e3.getSalary())/3<<endl;
}


int main()
{
    //test();
    int num=1;
    printf("%03d",num);
    return 0;
}
