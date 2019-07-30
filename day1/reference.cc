#include<iostream>
using namespace std;
void test(int *&p)
{
    int *q=new int(1);
    *q=2;
    p=q;
}



int main()
{
    int *p=NULL;
    test(p);
    if(p)
    {
        cout<<*p<<endl;
    }
    else 
    {
        cout<<"p is null"<<endl;
    }

return 0;
}
