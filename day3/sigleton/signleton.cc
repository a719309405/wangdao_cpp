#include<iostream>

using std::cout;
using std::endl;

class singleton
{
public:
    static singleton *getsingle(int x,int y)
    {
        if(Single)
        {
            return Single;
        }
        else 
        {
            Single = new singleton(x,y);
            return Single;
        }
    }
    void print() const
    {
        cout<<"x : "<<_x
            <<"  y : "<<_y<<endl;
    }
    
private:
    singleton(int x=0,int y=0)
    {
        _x=x;_y=y;
        cout<<"create func"<<endl;  
    }
    ~singleton(){}
    static singleton * Single;
    int _x;
    int _y;

};

singleton * singleton::Single=nullptr;
int main()
{
    
    singleton *s1=singleton::getsingle(1,2);
    s1->print();
    singleton *s2=singleton::getsingle(3,4);
    s2->print();
    cout<<"s1 :"<<s1<<endl;
    cout<<"s2 :"<<s2<<endl;

}
