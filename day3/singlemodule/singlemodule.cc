#include <iostream>
using std::cout;
using std::endl;
//Ҫ��: ����һ���ֻ࣬���ɸ��ഴ��Ψһ��һ������
//1. �ö�������ջ��ȫ�֣�����
//2. ֻ�ܽ��ö�����ڶ���
//Ӧ�ó���:
//1. �����õ���ģʽ�滻��ȫ�ֱ���
//2. �����ļ��еĴ洢���ǳ����������Ϣ
//3. �ʵ�⣬ ��ҳ��
class Singleton
{
public:
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
	//Point _pt;
	//Computer _pc;
	static Singleton* _pInstance;
};
Singleton* Singleton::_pInstance = nullptr;
//Singleton s3;//error
int main(void)
{
	//Singleton s1;//error �����ø�������ͨ��
	//Singleton s2;//error
	//Singleton * p1 = new Singleton();
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	Singleton* p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		<< "p2 = " << p2 << endl
		<< "p3 = " << p3 << endl;
	//delete p1;//error
	Singleton::destroy();
	return 0;
}
