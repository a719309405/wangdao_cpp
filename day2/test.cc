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
    }
    void print()
    {
        cout<<"print "<<_pstr<<endl;
    }

private:
    char * _pstr;
};
string getstring()
{
    string str("wangdao");
    str.print();
    return str;
}

int main()
{
    string str1;
    str1.print();
  const  int &ref=1;    
cout<<ref<<endl;
    return 0;

}

