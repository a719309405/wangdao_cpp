/*
	1.Ĭ�ϳ�ʼ���������С10��ȫ��Ϊ0��
	2.������ĳ�ʼ�������Ը�ǰ����Ԫ���ض�ֵ�ĳ�ʼ��
	3.�෽����
	push()�����ӡ������������ӣ���ӡ��ӳɹ�
	pop()�����ӡ��������-1���ǿյ�����������ջ��ֵ
	topele()�����ӡ��������-1���ǿշ���ջ��ֵ
	empty/full����/������1���ǿ�/��������0


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
