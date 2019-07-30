#pragma once
#include<iostream>

using std::cout;
using std::endl;


class line
{
    class linepimpl;
public:
    line(int x1,int y1,int x2,int y2);
    ~line();
    void print()const;
private:    
     linepimpl * pimpl;
};
