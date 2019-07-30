#include<string.h>
#include<iostream>

using std::cout;
using std::endl;

class string 
{
public:
    string()
        :_pstr(new char[1])
    {
        cout<<"default create func"<<endl;
    }
    string(const char *pstr)
        :_pstr(new char[strlen(pstr)+1])
    {
        strcpy(_pstr,pstr);
        cout<<"create func"<<endl;
    }
    string(const string & rhs)
        :_pstr(new char[strlen(rhs._pstr)+1]())// deep copy
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"copy func and deep copy"<<endl;
    }
    string & operator=(const string & rhs)
    {
        if(&rhs!=this)
        {
            delete [] _pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout<<"operator func"<<endl;
        }
        return *this;
    }
    ~string()
    {
        delete [] _pstr;
        cout<<"delete "<<endl;
    }
    void print()
    {
        cout<<"print "<<_pstr<<endl;
    }

private:
    char * _pstr;
};


int main()
{
    string str1;
    str1.print();

    string str2 = "Hello,world";
    string str3("wangdao");

    str2.print();       
    str3.print();   

    string str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
    return 0;

}

