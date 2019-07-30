#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
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

int main()
{
    mutexLock a;
    a.lock();
    a.unlock();
    return 0; 

}
