/*
	1.默认初始化，数组大小10，全置为0；
	2.待补充的初始化：可以给前几个元素特定值的初始化
	3.类方法：
	push()满则打印满，不满则添加，打印添加成功
	pop()空则打印，并返回-1，非空弹出，并返回栈顶值
	topele()空则打印，并返回-1，非空返回栈顶值
	empty/full：空/满返回1，非空/非满返回0


*/



#include<iostream>
using std::cout;
using std::endl;
class stack
{
public:
    stack()
    {
        for(int i=0;i<10;i++)
        {data[i]=0;}
        top=0;
        //size=0;
        cout<<"default stack create"<<endl;
    }
    stack(int a,int b=0,int c=0)
    {
        data[0]=a;
        top++;
        cout<<"stack creat"<<endl;
     //   size++
    }
    ~stack()
    {
        cout<<"default delete"<<endl;
    }
    void push(int a);
    int  pop();
    int topele();
    bool empty();
    bool full();
private:
    int data[10];
    int top;
    
    //int size;
};

void stack::push(int a)
{
    if(top==10)
    {
        cout<<"the stack is full"<<endl;
    }
    else
    {
     data[top]=a;
     top++;
     cout<<"add success"<<endl;
    }
}
int stack::pop()
{
    if(top==0)
    {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else
    {
        top--;
        return data[top];
    }
}
int stack::topele()
{
    if(top==0)
    {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else 
    {
        return data[top-1];
    }
}
bool stack::empty()
{
    if(top==0)
    {  
        cout<<"empty"<<endl;
        return 1;
    }
    else 
        return 0;
}
bool stack ::full()
{
    if(top==10)
    {
        cout<<"full"<<endl;
        return 1;
    }
    else 
        return 0;
}

int main()
{
    stack s;
    s.push(10);
    s.push(12);
    s.push(14);
    cout<<"the top element is "<<s.topele()<<endl;
    s.pop();
    cout<<"the top element is "<<s.topele()<<endl;

}
