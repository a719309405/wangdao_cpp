#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<limits>
#include<string>
#include<vector>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;


class String
{
public:
    String()
        :_pstr(new char[1])
    {
        _pstr[0]='\0';
        cout<<"default create success"<<endl;
    }
    String(const char *pstr)
        :_pstr(new char[strlen(pstr)+1])
    {
        strcpy(_pstr,pstr);
        cout<<"String(char*pstr)  create success"<<endl;
    }
    String(const String &str)
    :_pstr(new char[str.size()+1])
    {
        strcpy(_pstr,str.c_str());
        cout<<"String(const String &)  create success"<<endl;
    }
    String(const string &str)//copy create func
        :_pstr(new char[str.size()+1])
    {
        strcpy(_pstr,str.c_str());
        cout<<"copy create func success"<<endl;
    }
    ~String()
    {
        delete [] _pstr;
        cout<<"~String() success"<<endl;
    }
    void print() const 
    {
        cout<<_pstr<<endl;
    }

    String &operator=(const char* pstr)
    {
        delete [] _pstr;
        _pstr=new char[strlen(pstr)+1];
        strcpy(_pstr,pstr);
        cout<<"operator=(const char* pstr) success"<<endl;
        return *this;

    }
    String &operator=(const String &str)
    {
        if(this!=&str)
        {
            delete [] _pstr;
            _pstr=new char[strlen(str._pstr)+1];
            strcpy(_pstr,str._pstr);

        }
        cout<<"operator=(const String&) success"<<endl;
        return *this;
    }
    String &operator+=(const char *pstr)
    {
        strcat(_pstr,pstr);
        cout<<"operator+=(const char *) success"<<endl;
        return *this;
    }
    String &operator+=(const String &str)
    {
        strcat(_pstr,str._pstr);
        cout<<"operator+=(const String &) success"<<endl;
        return *this;
    }
    char &operator[](std::size_t idx)
    {
        if(idx>=0&&idx<strlen(_pstr))
        {
            cout<<"operator[](std::size_t idx) success"<<endl;
            return _pstr[idx];
        }
        else 
        {
            static char p='\0';
            cout<<"cross the broder"<<endl;
            return p;
        }
    }
    const char &operator[](std::size_t idx) const 
    {
        if(idx>=0&&idx<strlen(_pstr))
        {
            cout<<"const operator[](std::size_t idx) const  success"<<endl;
            return _pstr[idx];
        }
        else 
        {
            static char p='\0';
            cout<<"cross the broder"<<endl;
            return p;
        }
    }
    std::size_t size() const {return strlen(_pstr);}
    const char* c_str() const 
    {   
        cout<<"const c_str() const  success"<<endl;
        return _pstr;
    }
    char *getstr() 
    {
        return _pstr;
    }
    const char*getstr() const
    {
        return _pstr;
    }
    friend bool operator==(const String &a,const String &b); 
    friend bool operator!=(const String &a,const String &b); 
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);
    friend void realCharValue(std::istream &is,String &s);
private:
    char *_pstr;

};

bool operator==(const String &a,const String &b) 
{
    return strcmp(a._pstr,b._pstr)==0;
}
bool operator!=(const String &a,const String &b) 
{
    if(a==b)
        return false;
    return true;
}
bool operator<(const String &a, const String &b)
{
    if(strcmp(a._pstr,b._pstr)<0)
        return true;
    return false;
}
bool operator>(const String &a, const String &b)
{
    if(strcmp(a._pstr,b._pstr)>0)
        return true;
    return false;
}
bool operator<=(const String &a, const String &b)
{   
    if(strcmp(a._pstr,b._pstr)<=0)
        return true;
    return false;
}
bool operator>=(const String &a, const String &b)
{
    if(strcmp(a._pstr,b._pstr)>=0)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os<<s._pstr;
    return os;
}

void realCharValue(std::istream &is,String &s)
{
    if(s._pstr)
        delete [] s._pstr;
    vector<char> vec;
    vec.reserve(50);
    char a;
    while(a=cin.get(),a!='\n')
    {
        vec.push_back(a);
    }
    s._pstr=new char[vec.size()+1];
    int i;
    for( i=0;i<vec.size();i++)
    {
        s._pstr[i]=vec.at(i);
    }
    s._pstr[i]='\0';
 #if 0   
    char *temp1=(char *)calloc(0,5);
    char *temp2=(char *)calloc(0,5);
    
    int totalsize=5;
    while(is.get(temp2,5),temp2[strlen(temp2)]!='\n')
    {
    
        if(temp2[strlen(temp2)]!='\n')
        {
            temp1=(char*)realloc(temp1,totalsize*2);
            totalsize*=2;
            strcat(temp1,temp2);
            bzero(&temp2,sizeof(temp2));
            cout<<"diyici: "<<temp1<<endl;
        }
        
        if(is.bad())
        {
            cout<<"istream is corrupted"<<endl;
            return ;
        }
        else if(is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"pls cin agin"<<endl;
            continue;
        }
        cout<<"123"<<endl;
    }
    cout<<"-----"<<endl;
    
    cout<<temp2<<endl;
    strcat(temp1,temp2);
    cout<<temp1<<endl;
#endif
}


std::istream &operator>>(std::istream &is, String &s)
{
    
    realCharValue(is,s);
    return is;
}

String operator+(const String &a, const String &b)
{
    char *temp=new char[a.size()+b.size()+1]; 
    strcat(temp,a.c_str());
    strcat(temp,b.c_str());
    static String tmp(temp);
    return tmp; 
}
String operator+(const String &a, const char *pstr)
{
    char *temp=new char[a.size()+strlen(pstr)+1]; 
    strcat(temp,a.c_str());
    strcat(temp,pstr);
    static String tmp(temp);
    return tmp; 
}
String operator+(const char *pstr, const String &a)
{
    char *temp=new char[a.size()+strlen(pstr)+1]; 
    strcat(temp,pstr);
    strcat(temp,a.c_str());
    static String tmp(temp);
    return tmp; 
}



void test()
{
    String a("hello");
    String b("world");
    //------------------------------=
#if 0
    a.print();
    a="worlddd";
    a.print();
    a=b;
    a.print();
#endif
    //---------------------+=
#if 0
    a+="sss";
    a.print();
    a+=b;
    a.print();
#endif
    //---------------------------[]
#if 0
    cout<<a[0]<<endl;
    const String  c("sss");
    cout<<c[0]<<endl;
#endif
    //-----------------------------size() c_str
#if 0
    const String d("tttt");
    const char *str=d.c_str();
    cout<<str<<endl;
#endif
//----------------------------- == != >= <=
#if 0    
    if(a==b)
        cout<<"=="<<endl;
    if(a!=b)
        cout<<"!="<<endl;
    if(a>=b)
        cout<<">="<<endl;
    if(a<=b)
        cout<<"<="<<endl;
#endif
//------------------------------>> <<
#if 0
    String e;
    cin>>e;
    
    cout<<e<<endl;
    cin>>e;
    cout<<e<<endl;
#endif
//----------------------- +
#if 0
    String f;
    f=a+b;
    cout<<f<<endl;
    
    f=a+"ss";
    cout<<f<<endl;
    
    f="ss"+a;
    cout<<f<<endl;

#endif
}

int main()
{
    test();
    return 0;
}
