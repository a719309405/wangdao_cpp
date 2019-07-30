#include<stdlib.h>
#include <iostream>
#include<pthread.h>
using std::cout;
using std::endl;
class Singleton
{
public:

	static Singleton* getInstance()
	{
        pthread_once(&once,init);
		return _pInstance;
	}
    static void init()
    {
        ::atexit(destroy);
		_pInstance = new Singleton();
    }
	static void destroy()
	{
		if (_pInstance)
			delete _pInstance;
	}
private:
	Singleton() { cout << "Singleton()" << endl; }
	~Singleton() { cout << "~Singleton()" << endl; }
private:
	static Singleton* _pInstance;
    static pthread_once_t once;
};
pthread_once_t Singleton::once=PTHREAD_ONCE_INIT;
Singleton* Singleton::_pInstance = Singleton::getInstance();
int main(void)
{
	return 0;
}
