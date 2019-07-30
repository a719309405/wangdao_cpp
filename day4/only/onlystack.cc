#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class student
{
public:
    student(int id,const char *name)
    :_id(id)
    ,_name(new char[strlen(name)+1])
    {
        strcpy(_name,name);
        cout<<"create func success"<<endl;
    }
    ~student()
    {
        delete [] _name;
        cout<<"delete func success"<<endl;
    }
    void print()
    {
        cout<<"print : "<<_id <<"   "<<_name<<endl;
    }
private:
    static void *operator new(size_t size);
    static void operator delete(void *p);

private:
int _id;
char *_name;

};


int main()
{
    char name[10]="sun";
    student s1(123,"sun");
    s1.print();
    cout<<"----"<<endl;
    student *s2=new student(345,name);
    s2->print();
    return 0;
}
