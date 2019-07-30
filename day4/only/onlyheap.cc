#include<iostream>
#include<stdlib.h>
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
    void destroy()
    {
    //    this->~student();
        delete this;
    }
    void print()
    {
        cout<<"print : "<<_id <<"   "<<_name<<endl;
    }
    static void *operator new(size_t size)
    {
        cout<<"new a new object"<<endl;
        void *pret=(void*)malloc(size);
        return pret;
    }
    static void operator delete(void *p)
    {
        cout<<"delete a object"<<endl;
        free(p);
    }

private:

    ~student()
    {
        delete [] _name;
        cout<<"delete func success"<<endl;
    }
private:
int _id;
char *_name;

};


int main()
{
    char name[10]="sun";
   // student s1(123,"sun");
   // s1.print();
    cout<<"----"<<endl;
    student *s2=new student(345,name);
    s2->print();
    s2->destroy();
    
    return 0;
}
