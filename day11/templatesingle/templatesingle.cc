#include<stdlib.h>
#include<pthread.h>
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

template<class T,typename... Args>
class Single
{
public:
    static T *getInstance(Args... args)
    {
        pthread_once(&once,init);
    }
    
    static void  init() 
    {
        ::atexit(mydestroy);    
        if(t)
        {
            cout<<"single module"<<endl;
        }
        else 
        {
            t=new T(args...);
        }
    }
    static void mydestroy()
    {
        delete t;
    }
private:
    Single(Args... args)
    {
        cout<<"single default create"<<endl;
    }
    ~Single(){}
private:
    static T *t;
    static pthread_once_t once;
};

template<class T,typename... Args>
T * Single<T,Args...>::t=nullptr;
template<class T,typename... Args>
pthread_once_t Single<T,Args...>::once=PTHREAD_ONCE_INIT;



void test()
{
    point *p1 = Single<point,int, int >::getInstance(1,2);
    p1->print();
    point *p2 = Single<point,int, int >::getInstance(2,3);
    p2->print();
}
int main()
{
    test();
    return 0;
}
