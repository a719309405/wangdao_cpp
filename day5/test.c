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
using std::string;
using namespace log4cpp;
class Mylogger
{
public:
    void warn(const char * msg)
    {
        mycategory.warn(msg);
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
    static void destroy()
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

          ,mycategory(Category::getRoot().getInstance("mycategory"))
          {

              PatternLayout* ptnLayout1= new PatternLayout();
              ptnLayout1->setConversionPattern("%d %c [%p] %m%n");
              PatternLayout* ptnLayout2 = new PatternLayout();
              ptnLayout2->setConversionPattern("%d %c [%p] %m%n");
              OstreamAppender* postreamappender = new OstreamAppender("postreamappender",& cout);
              postreamappender->setLayout(ptnLayout2);
              mycategory.setPriority(Priority::DEBUG);
              mycategory.addAppender(rollingFileAppender);

              mycategory.addAppender(postreamappender);

              rollingFileAppender->setLayout(ptnLayout1);    
          }
    ~Mylogger()
    {
        Category::shutdown();
        cout<<"delete func success"<<endl;
    }
private:
    static Mylogger *mylog;
    RollingFileAppender * rollingFileAppender;

    Category & mycategory;
};


Mylogger *Mylogger::mylog=nullptr;

#define premix(msg) string("[").append(__FILE__).append(" : ").append(std::to_string(__LINE__)).append(" : ").append(__FUNCTION__).append("]").append(msg)
#define LogWarn(msg)  Mylogger::getInstance()->warn(premix("this is warn message").c_str());


int main()
{
    if(1)//ERORR
    {
    LogWarn("this is warn message");
    }
    Mylogger::destroy();
    return 0;

}

