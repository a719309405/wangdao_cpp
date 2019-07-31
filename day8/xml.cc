#include<stdio.h>
#include <string>
#include <iostream>
#include<fstream>
#include <vector>
#include <boost/regex.hpp>

#include "../tinyxml2/tinyxml2.h"

using namespace tinyxml2;
using namespace std;
using namespace boost;
using std::vector;

typedef struct rssitem
{
    string title;
    string link;
    string description;
    string content;
}rssitem;

class RssReader
{
public:
    RssReader();
    
    void parseRss();//解析
    void dump(const string & filename= "pagelib.dat");//输出
private:
    vector<rssitem> _rss;
};   




RssReader::RssReader()
{
    XMLDocument* doc = new XMLDocument();  
    doc->LoadFile("coolshell.xml");
    /*    if(doc->LoadFile("persons.xml") != XML_NO_ERROR)
          {
          cout<<"read file error!"<<endl;
    //exit;
    }
    */
    XMLElement* root =doc->RootElement();
    XMLElement* channel=root->FirstChildElement("channel");
    if(NULL==channel)
    {
        cout<<"get first child element erorr"<<endl;
    }
    XMLElement *title=channel->FirstChildElement("title");
    cout<<title->GetText()<<endl;
    cout<<title->Name()<<endl;
    XMLElement *item=title->NextSiblingElement();
    while(item=item->NextSiblingElement(),strcmp(item->Name(),"item")!=0)
    {    }
    cout<<item->Name()<<endl;
    /*XMLElement *ctitle=item->FirstChildElement();
    cout<<ctitle->GetText()<<endl;
    cout<<ctitle->Name()<<endl;
    */
    while(item)
    {
        rssitem tmp;
        cout<<item->Name()<<endl;
        cout<<"in item"<<endl;
        XMLElement *child_item=item->FirstChildElement();
        while(child_item)
        {
            char *name=new char[strlen(child_item->Name())+1];
            strcpy(name,child_item->Name());
            if(strcmp(name,"title")==0)
            {
                cout<<"child:  "<<child_item->Name()<<endl;
                tmp.title=tmp.title.replace(tmp.title.begin(),tmp.title.end(),child_item->GetText());
                cout<<tmp.title<<endl;
            }
            else if(strcmp(name,"link")==0)
            {
                
                cout<<"child:  "<<child_item->Name()<<endl;
                tmp.link=tmp.link.replace(tmp.link.begin(),tmp.link.end(),child_item->GetText());
                cout<<tmp.link<<endl;
            }
            else if(strcmp(name,"description")==0)
            {
                
                cout<<"child:  "<<child_item->Name()<<endl;
                tmp.description=tmp.description.replace(tmp.description.begin(),tmp.description.end(),child_item->GetText());
                cout<<tmp.description<<endl;
            }
            else if(strcmp(name,"content:encoded")==0)
            {
                
                cout<<"child:  "<<child_item->Name()<<endl;
                tmp.content=tmp.content.replace(tmp.content.begin(),tmp.content.end(),child_item->GetText());
                cout<<tmp.content<<endl;
            }
            


            child_item=child_item->NextSiblingElement();
        }
        _rss.push_back(tmp);
        item=item->NextSiblingElement();
    }
    dump();
}
void RssReader::dump(const string &filename)
{
    boost::regex expr("<.*?>");
    string tihuan ="";
    int id=1;
    ofstream ofs(filename.c_str(),std::ios::app);
    vector<rssitem>::iterator _begin=_rss.begin();
    vector<rssitem>::iterator _end=_rss.end();
    
    while(_begin!=_end)
    {
        ofs<<"<doc>"<<endl;
        ofs<<"   <docid>"<<id++<<"</docid>"<<endl;
        ofs<<"   <title>"<<_begin->title<<"</title>"<<endl;
        ofs<<"   <link>"<<_begin->link<<"</link>"<<endl;
        ofs<<"   <description>"<<boost::regex_replace(_begin->description,expr,tihuan)<<"</description>"<<endl;
        ofs<<"   <content>"<<boost::regex_replace(_begin->content,expr,tihuan)<<"</content>"<<endl;
        ofs<<"</doc>"<<endl;
        ++_begin;
    }
}

int main()
{
    RssReader temp;
    return 0;
}
