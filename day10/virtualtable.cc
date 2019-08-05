#include<iostream>

using std::cout;
using std::endl;

class A 
{
public:
    A(long x)
    {_ia=x;cout<<"a default create"<<endl;}

    virtual void func1(){cout<<"this is func1"<<endl;}
    virtual void func2(){cout<<"this is func2"<<endl;}
    virtual void func3(){cout<<"this is func3"<<endl;}

    //virtual ~a(){cout<<"delete a"<<endl;
private:
    long _ia;
};


class B
:public A 
{
public:
    B(long x,long y)
    :A(x)
    ,_ib(y)
    {cout<<"b default create"<<endl;}

    virtual void func1(){cout<<"B:this isfunc 1"<<endl;}
    virtual void funcb(){cout<<"B:funcb"<<endl;}
private:
    long _ib;
};
class C
:public B
{
public: 
    C(long x,long y,long z)
    :B(x,y)
    ,_ic(z)
    {cout<<"c default"<<endl;}

    virtual void funcb(){cout<<"C:funcb"<<endl;}
private:
    long _ic;
};


int main()
{
#if 0
    A tmp(5);
    cout<<"sizeof(a)"<<sizeof(tmp)<<endl;
    long *p=(long*)&tmp;
    cout<<p[0]<<endl;
    cout<<p[1]<<endl;
    
    typedef void (*function)(void);
    
    long *p2=(long*)p[0];
    function a=(function)p2[0];
    a();
    a=(function)p2[1];
    a();
#endif 
#if 1    
    B b(3,4);
   // A *tmpa=&;
    cout<<"sizeof(b)"<<sizeof(b)<<endl;
    long *p=(long*)&b;
    cout<<p[0]<<endl;
    cout<<p[1]<<endl;
    cout<<p[2]<<endl;
    typedef void (*function)(void);
    
    long *p2=(long*)p[0];
    function a=(function)p2[0];
    a();
    a=(function)p2[1];
    a();
    a=(function)p2[2];
    a();
    a=(function)p2[3];
    a();
   //A &tmp=b;

    

    C c(11,12,12);
    cout<<"sizeo(c)"<<sizeof(c)<<endl;



#endif
    return 0;
}
