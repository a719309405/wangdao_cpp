#include<iostream>

using std::cout;
using std::endl;

template<class T,int qsize=10>
class queue
{
public:
    queue()
    :front(0)
    ,rear(0)
    {
        cout<<"queue default create"<<endl;
    }
    bool inque(const T &);
    T outque();
    bool isempty();
    bool isfull();
    T getquefront();
    T getquerear();
private:
    T que[qsize];
    int front;
    int rear;
};


template<class T,int qsize>
bool queue<T,qsize>::isempty()
{
    return (front==rear);
}
template<class T,int qsize>
bool queue<T,qsize>::isfull()
{
    if((rear+1)%qsize==front)
        return true;
    return false;
}
template<class T,int qsize>
bool queue<T,qsize>::inque(const T &a)
{
    if(!isfull())
    {
        que[rear]=a;
        rear=(rear+1)%qsize;
        return true;
    }
    else 
    {
        cout<<"full inque fail"<<endl;
        return false;
    }
}
template<class T,int qsize>
T queue<T,qsize>::outque()
{
    if(!isempty())
    {
        T temp=que[front];
        front=(front+1)%qsize;
        return temp;
    }
    else 
    {
        cout<<"empty,outque fail"<<endl;
        return -1;
    }
}

template<class T,int qsize>
T queue<T,qsize>::getquerear()
{
    if(!isempty())
        return que[(rear-1+qsize)%qsize];
    else
    {
        
        cout<<"empty,getquerear fail"<<endl;
        return -1;
    }
}
template<class T,int qsize>
T queue<T,qsize>::getquefront()
{
    if(!isempty())
        return que[front];
    else
    {
        
        cout<<"empty,getquefront fail"<<endl;
        return -1;
    }
}
void test()
{
    queue<int> q;
    if(q.isempty())
        cout<<"empty"<<endl;
    
    for(int idx=1;idx<=12;idx++)
        q.inque(idx);
    for(int idx=1;idx<=10;idx++)
    {
        cout<<q.getquefront()<<endl;
        q.outque();
    }
}
int main()
{
    test();
    return 0;
}
