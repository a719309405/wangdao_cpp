#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>
using std::cout;
using std::endl;


class mutexLock
{
public:
    mutexLock()
    {
        cout<<"default create success"<<endl;
    }
    void lock();
    void unlock();
    int getvalue(){return value;}
private:
static int value;
};
int mutexLock::value=0;

void mutexLock::lock()
{
   while(__sync_bool_compare_and_swap(&value,0,1)==false)
   {
   }
   cout<<"the lock is be locked"<<endl;
}
void mutexLock::unlock()
{
    
   __sync_fetch_and_sub(&value,1);
    cout<<"the lock is be unlocked"<<endl;
}
void *func(void *p)
{
    mutexLock *a=(mutexLock *)p;
        a->lock();     
        cout<<"pid 2 working"<<endl;
        sleep(1);
        a->unlock();
    pthread_exit(NULL);
}
int main()
{
    mutexLock a;
    pthread_t pthid;
    pthread_create(&pthid,NULL,func,&a);
    a.lock();
    cout<<"pid 1 working"<<endl;
    sleep(10);
    a.unlock();
    pthread_join(pthid,NULL);
    return 0; 
}
