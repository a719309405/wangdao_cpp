#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::fstream;
using std::vector;
using std::stringstream;
#define wordNum 26

class trienode
{
public:
    trienode()
    :num(1)
    ,isend(false)
    {
        for(int i=0;i<26;i++)
            {son[i]=NULL;}
        //cout<<"new node create"<<endl;
    }
    ~trienode()
    {
        delete []  *son;
        //cout<<"node is be delete"<<endl;
    }
friend bool insert(trienode *root,string word);
friend void find(trienode *root);
private:
    int num;
    bool isend;
    trienode  *son[26];
    char val;
};

bool insert(trienode *root,string word)
{
    trienode *pnode=root;
    for(int i=0;i<word.size();i++)
    {  
        //cout<<word<<endl;
        //cout<<word.size()<<"------------"<<endl;
        if(pnode->son[ word[i]-'a' ]==NULL)
        {
            trienode *temp=new trienode;
            temp->val=word[i];
            if(i+1==word.size())//end
            {
                temp->isend=true;
             //   cout<<word<<" success"<<endl;
              //  cout<<temp->num<<endl;
                pnode->son[word[i]-'a']=temp;
                return true;
            }
            pnode->son[word[i]-'a']=temp;
        }
        else
        {
            //cout<<"befor num++"<<endl;
            pnode->son[word[i]-'a']->num++;
            //if(i+1==word.size())
             //   cout<<pnode->son[word[i]-'a']->num<<endl;
            //cout<<"after num++"<<endl;
        }
        pnode=pnode->son[word[i]-'a'];
    }
}
string wordtemp;
stringstream ss;
vector<string> file2;
void find(trienode *root)
{
    
    trienode *p=root;
    if(p->isend)
        {
            //file2.push_back(wordtemp);
            //ss<<p->num;
            //string a=ss.str();
            //file2.push_back(a);
            //ss.clear();
            ofstream ofs;
            ofs.open("s.txt",std::ios::app);
            ofs<<wordtemp;
            ofs<<"  ";
            ofs<<p->num;
            ofs<<"\n";
            ofs.close();
            //wordtemp="";
            //wordtemp=wordtemp.substr(0,deep);
        }
    for(int i=0;i<26;i++)
    {
        if(p->son[i]!=NULL)
            {
                wordtemp.push_back(p->son[i]->val);
                find(p->son[i]);
            }
    }
    wordtemp.pop_back();
}
vector<string> file;
int main()
{

    ifstream ifs;
    ifs.open("a.txt");
    string word;
    if(!ifs)
    {
        cout<<"ifstream open file a.txt error "<<endl;
        return 0;
    }
    while(ifs>>word)
    {
        file.push_back(word);   
    }
    int totalCount=0;
    
    trienode root;
    for(auto & word : file)
    {
        if(word[0]>='0'&&word[0]<='9')
        {
            
        }
        else
        {
            
            insert(&root,word);    
            totalCount++;
        }   
    }
   find(&root);
#if 0 
    ofstream ofs;
    ofs.open("s.txt");
   
   for(auto & line : file2)
   {
        ofs<<line<<"\n"; 
   }
#endif
   cout<<"total word:"<<totalCount<<endl;
    ifs.close();
}





