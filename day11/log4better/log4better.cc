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
    template<typename... Args>
    void warn(Args... args)
    {
        mycategory.warn(args...);
    }
    void error(const char * msg)
    {
        mycategory.error(msg);
    }
    template<typename... Args>
    void error(Args... args)
    {
        mycategory.error(args...);
    }
    void info(const char * msg)
    {
        mycategory.info(msg);
    }
    template<typename... Args>
    void info(Args... args)
    {
        mycategory.info(args...);
    }
    void debug(const char * msg)
    {
        mycategory.debug(msg);
    }
    template<typename... Args>
    void debug(Args... args)
    {
        mycategory.debug(args...);
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
template<typename... Args>
void LogWarn(string msg,Args... args)  
{
    Mylogger::getInstance()->warn(premix(msg).c_str(),args...);
}
template<typename... Args>
void LogError(string msg,Args... args)  
{
    Mylogger::getInstance()->error(premix(msg).c_str(),args...);
}
template<typename... Args>
void LogDebug(string msg,Args... args)  
{
    Mylogger::getInstance()->debug(premix(msg).c_str(),args...);
}
template<typename... Args>
void LogInfo(string msg,Args... args)  
{
    Mylogger::getInstance()->info(premix(msg).c_str(),args...);
}





int main()
{
    if(1)//ERORR
    {
        
       LogWarn("this is warn message number=%d str=%s",10,"hellowolrd");
       LogError("this is Error message number=%d str=%s",20,"hi");       
       LogInfo("this is info message number=%d str=%s",30,"nihao");       
       LogDebug("this is debug message number=%d str=%s",40,"bye");       
    
    }
    Mylogger::destroy();
    return 0;
}
