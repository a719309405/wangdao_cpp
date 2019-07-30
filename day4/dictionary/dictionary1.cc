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
    :num(0)
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
        cout<<word<<endl;
        if(pnode->son[ word[i]-'a' ]==NULL)
        {
            trienode *temp=new trienode;
            temp->val=word[i];
            temp->num=1;
            if(i+1==word.size())//end
            {
                temp->isend=true;
                pnode->son[word[i]-'a']=temp;
                return true;
            }
            pnode->son[word[i]-'a']=temp;
        }
        else
        {
            if(i+1==word.size())
            {
               if(pnode->son[word[i]-'a']->isend==false)
                {
                     pnode->son[word[i]-'a']->num=0;
                }
                pnode->son[word[i]-'a']->isend=true;
                pnode->son[word[i]-'a']->num++;
            }
        }
        pnode=pnode->son[word[i]-'a'];
    }
}
string wordtemp;
ofstream ofs;
void find(trienode *root)
{
    trienode *p=root;
    if(p->isend)
        {
            ofs<<wordtemp;
            ofs<<"  ";
            ofs<<p->num;
            ofs<<"\n";
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

    ofs.open("s.txt",std::ios::app);
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
    //int totalCount=0;
    trienode root;
    for(auto & word : file)
    {
        if(word[0]>='0'&&word[0]<='9')
        { 
        }
        else
        {
            insert(&root,word);    
            //totalCount++;
        }   
    }
    find(&root);
    //cout<<"total word:"<<totalCount<<endl;
    ifs.close();
    ofs.close();
}





