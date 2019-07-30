#include<iostream>
using std::cout;
using std::endl;

int array[5]={1,2,3,4,5};
int &test(int idx)
{
    return array[idx];

}


int main()
{
    int a=0;
    a=test(1);
    cout<<a<<endl;
    test(1)=4;
    cout<<array[1]<<endl;
return 0;


}
