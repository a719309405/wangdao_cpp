#include<func1.h>
#include<iostream>

using std::cout;
using std::endl;

class mutexLock
{
public:
    mutexLock()
    {
        pthread_mutex_init(&mylock,NULL);
        cout<<"default create success"<<endl;
    }
    pthread_mutex_t *getmutex()
    {
//        printf("mylock :%p",&mylock);
        return &mylock;
    }
    void lock();
    void unlock();
private:
pthread_mutex_t mylock;

};


void mutexLock::lock()
{

    pthread_mutex_lock(&mylock);
    cout<<"the lock is be locked"<<endl;
}
void mutexLock::unlock()
{
    pthread_mutex_unlock(&mylock);
    cout<<"the lock is be unlocked"<<endl;
}



class condition
{
public:
    static condition *getcondition()
    {
        if(mycond)
        {
            return mycond;
        }
        else 
        {
            mycond=new condition();
            return mycond;
        }
    }
    static void destorycond()
    {
        if(mycond)
        {
            delete mycond;
        }
        else 
        {
        
        }
    }
    void mutexunlock();
    void wait();
    void notify();
    void notifyall();
private:
    condition()
    {
        pthread_cond_init(&cond,NULL);
       num=0;
       cout<<"default create cond success"<<endl;
        
    }
    ~condition()
    {
        pthread_cond_destroy(&cond);
        cout<<"cond is be destoryed"<<endl;
    }
    static condition * mycond;
    pthread_cond_t cond;
    class mutexLock a;
    int num;
};
condition * condition::mycond=nullptr;

void condition::mutexunlock()
{
    a.unlock();
}
void condition::wait()
{
    
 //   printf("#2mylock: %p",a.getmutex());
    a.lock();
    num++;
    cout<<"condition wait"<<endl;
    pthread_cond_wait(&cond,a.getmutex());
}
void condition::notify()
{
    pthread_cond_signal(&cond);
    num--;
    cout<<"condition notify"<<endl;
}
void condition::notifyall()
{
    for(int i=0;i<num;i++)
    {
    pthread_cond_signal(&cond);
    cout<<"condition notify"<<endl;
    }
    num=0;
}
void * func(void * p)
{
    
    condition *mycond=(condition *)p;
    mycond->wait();
    mycond->mutexunlock();
    cout<<"working--------------"<<endl;
    pthread_exit(NULL);
}
int main()
{
    condition *mycond=condition::getcondition();
    //mylock.lock();
    pthread_t pthid1,pthid2;
    pthread_create(&pthid1,NULL,func,mycond);
    pthread_create(&pthid2,NULL,func,mycond);

    sleep(2);
    mycond->notifyall();
    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    condition::destorycond();
    return 0;
}
