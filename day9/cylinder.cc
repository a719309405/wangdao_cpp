#include<iostream>

#define pi 3.14
using std::cout;
using std::endl;


class circle
{
public:
    circle()
    :_radius(0)
    {cout<<"circle default create"<<endl;}
    circle(double r)
    :_radius(r)
    {cout<<"circle (double r) create"<<endl;}
    
    double getArea(){return pi*_radius*_radius;}
    double getPerimeter(){return pi*2*_radius;}
    void show()
    {
        cout<<"radius: "<<_radius<<" , perimeter: "<<getPerimeter()<<" , area: "<<getArea()<<endl;
    }

private:
double _radius;
};

class cylinder
:public circle
{
public:
    cylinder(double r,double h)
    :circle(r)
    ,_height(h)
    {cout<<"cylinder default create"<<endl;}
    
    double getVolume(){return getArea()*_height;}
    void showVolume(){cout<<"cylinder volume is "<<getVolume()<<endl;}
private:
    double _height;
};

void test()
{
    circle c1;
    c1.show();
    circle c2(2);
    c2.show();
    

    cylinder cl1(2,3);
    cl1.showVolume();

}


int main()
{
    test();
    return 0;
}







