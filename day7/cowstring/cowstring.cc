#include<string.h>
#include<iostream>

using std::cout;
using std::endl;
using std::ostream;

class cowstring
{
public:
    class charcow
    {
    public:
        charcow(cowstring &self,int idx)
        :_self(self)
        ,_idx(idx)
        { 
        }
        operator char()
        {
            return _self._pstr[_idx];
        }
        char &operator=(const char &x);
    private:
        cowstring &_self;
        int _idx;
    };
    cowstring()
    :_pstr(new char[1+4] + 4)
    {
        refinit();
        cout<<"cowstring default create"<<endl;
    }
    cowstring(const char *str)
    :_pstr(new char[1+4+strlen(str)] + 4)
    {
        strcpy(_pstr,str);
        refinit();
        cout<<"cowstring(const char*) create"<<endl;
    }
    cowstring(const cowstring &cow)
    :_pstr(new char[1+4+strlen(cow._pstr)] + 4)
    {
        strcpy(_pstr,cow._pstr);
        refinit();
        cout<<"cowstring(const cowstring) create"<<endl;
    }
    cowstring &operator=(const cowstring &cow)
    {
        if(this!=&cow)
        {   
            release();
            _pstr=cow._pstr;
            refincrease();
            cout<<"operator="<<endl;
        }
        return *this;
    }

    int size(){return strlen(_pstr);}
    char *c_str()
    {
        char *temp=new char[size()+1];
        strcpy(temp,_pstr);
        return temp;
    }
    ~cowstring()
    {   
        release();
    }
    void refprint()
    {
        cout<<*(int*)(_pstr-4)<<endl;
    }
    void release()
    {
        refdecrease();
        refprint();
        cout<<c_str()<<endl;
        if(ref()==0)
        {
            delete [] (char*)(_pstr-4);
            cout<<"release"<<endl;
        }
    }
    charcow &operator[](int idx);
friend ostream &operator<<(ostream &os,const cowstring &cow);
private:
    void refinit()
    {
        *(int*)(_pstr-4)=1;
    }
    int ref()
    {
        return *(int*)(_pstr-4);
    }
    void refincrease()
    {
        ++*(int*)(_pstr-4);
    }
    void refdecrease()
    {
        --*(int*)(_pstr-4);
    }
    char * _pstr;
};

ostream &operator<<(ostream &os,const cowstring &cow)
{
    os<<cow._pstr;
    return os;
}


cowstring::charcow &cowstring::operator[](int idx)
{
    charcow *temp=new charcow(*this,idx);
    return *temp;
}

char &cowstring::charcow::operator=(const char &x)
{
    if(_idx>=0&&_idx<_self.size())
    {
        _self.release();
        char *temp=new char[_self.size()+1+4]+4;
        strcpy(temp,_self._pstr);
        _self._pstr=temp;
        _self.refinit();
        _self._pstr[_idx]=x;
        return _self._pstr[_idx];
    }
    else 
    {
        static char temp='\0';
        return temp;
    }
}
int main()
{
    cowstring c1("hello,world");
#if 0
    cowstring c2("nihao");
    c2=c1;
    c2.refprint();
    cout<<c2<<endl;
    c2[0]='x';
    c2.refprint();
    c1.refprint();
    cout<<c1<<endl;
    cout<<c2<<endl;
#endif
    cowstring c3("aaa");
    c3=c1;
    cout<<c3[0]<<endl;
    c1.refprint();
    c3.refprint();
    cout<<c1<<endl;
    cout<<c3<<endl;
    return 0;
}
