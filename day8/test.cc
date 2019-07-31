#include <iostream>
#include <boost/regex.hpp>
using namespace std;
using namespace boost;
int main()
{
    std::string str = "<asd>hello,world<fsfs.g.> (全文完)asdad<ds.a.sda>\n<asdasd>aaa";

    boost::regex expr("<.*?>");//s-space 任何空格字符
    boost::regex expr2("/(.*?/)");

    std::string tihuan = "\0";
    std::string tmp;
    tmp= boost::regex_replace(str, expr, tihuan);
    cout<<"begin1: "<<tmp<<endl;
    tmp= boost::regex_replace(tmp, expr2, tihuan);
    cout<<"begin: "<<tmp<<endl;
    return 0;
}
