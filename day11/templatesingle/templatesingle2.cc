#include<string.h>
#include<stdlib.h>
#include<iostream>

using std::cout;
using std::endl;

class point
{
public:
    point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout<<"point default create"<<endl; 
    }
    ~point(){
        cout<<"point delete "<<endl; 
    }
    void print()const
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
private: 
    int _ix;
    int _iy;
};

class computer
{
public:
    computer(const char *name,const long price)
    :_name(new char[strlen(name)+1]())
    ,_price(price)
    {
        strcpy(_name,name);
        cout<<"computer default create"<<endl;
    }
    ~computer()
    {
        delete [] _name;
    }
    void print()const 
    {
        cout<<"name: "<<_name<<" price: "<<_price<<endl;
    }

private:
    char *_name;
    long _price;
};

template<class T,typename... Args>
class Single
{
public:
    static T *getInstance(Args... args)
    {
        ::atexit(mydestroy);
        if(t)
            cout<<"single module"<<endl;
        else 
            t=new T(args...);
        return t;
    }
    static void mydestroy()
    {
        if(t)
            {
                delete t;
                t=NULL;
            }
    }   
private:
    Single(Args... args)
    {
        cout<<"single default create"<<endl;
    }
    ~Single(){}
private:
    static T *t;
};

template<class T,typename... Args>
T * Single<T,Args...>::t=nullptr;

void test()
{
    point *p1 = Single<point,int, int >::getInstance(1,2);
    p1->print();
    point *p2 = Single<point,int, int >::getInstance(2,3);
    p2->print();
    
    computer *p3=Single<computer,char*,long>::getInstance("huipu",10000);
    p3->print();
    computer *p4=Single<computer,char*,long>::getInstance("hellow",20000);
    p4->print();
}
int main()
{
    test();
    return 0;
}
