
#include<iostream>
#include<vector>
#include<istream>
#include<ostream>
#include<fstream>
using std::cout;
using std::endl;
using std::ifstream;

int main()
{
    ifstream isf;
    isf.open("test.txt");
    if(!isf.good())
    {
        cout<<"cant open"<<endl;
    }


}
