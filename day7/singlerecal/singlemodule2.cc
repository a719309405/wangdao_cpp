#include<stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
class Singleton
{
public:

	static Singleton* getInstance()
	{
		if (nullptr == _pInstance) {
            ::atexit(destroy);
			_pInstance = new Singleton();
		}
		return _pInstance;
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
};
Singleton* Singleton::_pInstance = Singleton::getInstance();
int main(void)
{
   

	return 0;
}
