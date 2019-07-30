/*
	1.循环队列，共10个元素，默认初始化为全0
	2.待完成初始化，即给定几个值
	3.函数：
	push()满则打印，返回0，不满则添加并打印，返回1
	pop()空则打印，返回0，非空则取出，并打印返回取出的值





*/



#include<iostream>
using std::cout;
using std::endl;


class queue
{
public:
    queue()
    :front(0)
    ,rear(0)
    ,size(0)
    {
        for(int i=0;i<10;i++)
        {
            data[i]=0;
        }
        cout<<"1#default create queue success"<<endl;
    }
    queue(int a)
    :front(1)
    ,rear(0)
    ,size(1)
    {
        
        for(int i=1;i<10;i++)
        {
            data[i]=0;
        }
        data[0]=a;
        cout<<"2#default create queue success"<<endl;
    }
    ~queue()
    {
        cout<<"default delete"<<endl;
    }
    int push(int a);
    int pop();
    int frontele();//front element
    int rearele();//rear element
    bool empty();
    bool full();
private:
int data[10];
int front;
int rear;
int size;
};
bool queue::empty()
{
    if(front==rear)
    {
        cout<<"queue is empty"<<endl;
        return 1;
    }
    else 
    {
        return 0;
    }
}
bool queue::full()
{
    if((front+1)%10==rear)
    {
        cout<<"queue is full"<<endl;
        return 1;
    }
    else 
    {
        return 0;
    }
}
int  queue::push(int a)
{
    if(this->full())
    {
        cout<<"the cycle queue is full";
        return 0;
    }
    else 
    {
        data[front]=a;
        front=(front+1)%10;
        cout<<"add success"<<endl;
        return 1;
    }
}
int queue::pop()
{
    if(this->empty())
    {
        cout<<"queue is empty"<<endl;
        return 0;
    }
    else 
    {
        int temp=data[rear];
        rear=(rear+1)%10;
        return temp;
    }
}
int queue::frontele()
{
    if(this->empty())
    {
        cout<<"queue is empty"<<endl;
        return 0;
    }
    else 
    {
        return data[(front-1)%10];
    }
}
int queue::rearele()
{
    if(this->empty())
    {
        cout<<"queue is empty"<<endl;
        return 0;
    }
    else 
    {
        return data[rear];
    }
}
int main()
{
    queue q;
    q.push(1);

    q.push(2);
    q.push(3);
    cout<<"front ele: "<<q.frontele()<<endl;
    q.push(4);
    cout<<"pop ele:"<<q.pop()<<endl;
    cout<<"rear ele:"<<q.rearele()<<endl;
    cout<<"front ele"<<q.frontele()<<endl;
    
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);

    q.push(1);

    q.push(1);
    return 0;
}
