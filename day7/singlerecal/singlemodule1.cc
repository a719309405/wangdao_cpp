#include <iostream>
using std::cout;
using std::endl;
class Singleton
{
public:
    class singlerelease
    {
    public:
        singlerelease(){cout<<"singlerelease "<<endl;}
        ~singlerelease()
        {
            cout<<"singlerelease delete"<<endl;
            destroy();
        }
    };



	static Singleton* getInstance()
	{
		if (nullptr == _pInstance) {
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
    static singlerelease  a;
};
Singleton* Singleton::_pInstance = nullptr;
Singleton::singlerelease Singleton::a;
int main(void)
{
	Singleton* p1 = Singleton::getInstance();
    
	return 0;
}
