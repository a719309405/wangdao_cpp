
#include"pimpl.h"
using std::cout;
using std::endl;

class line::linepimpl
{
public:
    class point
    {
    public:
        point(int x,int y)
        :_ix(x)
        ,_iy(y)
        {
           cout<<"point default create"<<endl; 
        }
        ~point(){
           cout<<"point delete "<<endl; 
        }
        void print()const
        {
            cout<<"("<<_ix<<","<<_iy<<")"<<endl;
        }
    private: 
        int _ix;
        int _iy;
    };
    linepimpl(int x1,int y1,int x2,int y2)
    :pt1(x1,y1)
    ,pt2(x2,y2)
    {
        cout<<"line default create"<<endl;
    }
    ~linepimpl()
    {
        cout<<"line delete "<<endl;
    }
    void lineprint() const
    {
        pt1.print();cout<<"---->";pt2.print();
    }

private:
    point pt1;
    point pt2;
};

line::line(int x1,int y1,int x2,int y2)
:pimpl(new linepimpl(x1,y1,x2,y2))
{
}
void line::print()const  
{
    pimpl->lineprint();
}
line::~line()
{
    delete pimpl;
}


