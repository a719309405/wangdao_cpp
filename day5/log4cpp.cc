#include<stdio.h>
#include<log4cpp/Category.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using namespace log4cpp;
class Mylogger
{
public:
    void warn(const char * msg,const char * func)
    {
        mycategory.warn("file: %s func: %s  line: %d %s this is warn message",__FILE__,func,__LINE__,msg);
    }
    void error(const char * msg,const char *func)
    {
        mycategory.error("file: %s func: %s  line: %d %s this is warn message",__FILE__,func,__LINE__,msg);
    }
    void debug(const char * msg,const char *func)
    {
        mycategory.debug("file: %s func: %s  line: %d %s  this is error message",__FILE__,func,__LINE__,msg);
    }
    void info(const char * msg,const char * func)
    {
        mycategory.info("file: %s func: %s  line: %d %s  this is error message",__FILE__,func,__LINE__,msg);
    }
    static Mylogger * getInstance()
    {
        if(!mylog)
        {
            mylog=new Mylogger();
            return mylog;
        }
        else 
            return mylog; 
    }
    void destroy()
    {
        if(mylog)
            delete mylog;
    }
private:
    Mylogger()
        : rollingFileAppender(new RollingFileAppender(
                                                      "rollingFileAppender",
                                                      "rollwangdao.log",
                                                      1024,
                                                      5))
          ,ptnLayout(new PatternLayout())
          ,mycategory(Category::getRoot().getInstance("mycategory"))
    {
         ptnLayout->setConversionPattern("%d %c [%p] %m%n");
        mycategory.setPriority(Priority::DEBUG);
        mycategory.addAppender(rollingFileAppender);
   
        rollingFileAppender->setLayout(ptnLayout);    
    }
    ~Mylogger()
    {
        Category::shutdown();
        cout<<"delete func success"<<endl;
    }
private:
    static Mylogger *mylog;
    RollingFileAppender * rollingFileAppender;
    PatternLayout * ptnLayout;
    Category & mycategory;
};


Mylogger *Mylogger::mylog=nullptr;

void test()
{
    

}

int main()
{
    Mylogger *my=Mylogger::getInstance();
    char func[20]={0};
    sprintf(func,__FUNCTION__);
    if(1)//ERORR
    {
        my->warn("fatal error",func);
    }
    my->destroy();
    return 0;

}
