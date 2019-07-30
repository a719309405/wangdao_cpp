#include<string.h>
#include<iostream>

using std::cout;
using std::endl;

class computer 
{
    public:
    computer()
    {
        _brand=new char[(strlen(_brand)+1)];
        _price=0;
        cout<<"default create func:"<<endl
            <<"brand: "<<_brand<<endl
            <<"price: "<<_price<<endl;
    }
    ~computer()
    {
        delete(_brand);
        cout<<"default delete func"<<endl;
    }
    private:
    char *_brand;
    float _price;
};


int main()
{
    computer a;
    return 0;

}

