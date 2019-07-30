#include<log4cpp/Category.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>

#include<iostream>

using std::cout;
using std::endl;
using namespace log4cpp;


int main()
{
    OstreamAppender *ostreamappender=new OstreamAppender("ostreamappender",&cout);
    ostreamappender->setLayout(new BasicLayout());

    Category &root=Category::getRoot();
    root.setPriority(Priority::DEBUG);
    root.addAppender(ostreamappender);
    
    root.alert("this is alert message");


    Category::shutdown;
    return 0;

}
