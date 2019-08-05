#include<stdio.h>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::cin;


int totallife_blue=100;
int totallife_red=100;
int mytime=0;
int num_blue=0;
int num_red=0;
int lifearry[5]={0};

class warrior
{
public:
    warrior(int life)
    :_life(life)
    {
        //cout<<"warrior (double) create"<<endl;
    }
    virtual
    void display_warrior(){}
    int getLife(){return _life;}
private:
    int _life; 
};


class dragon
:public warrior
{
public:
    dragon(int life,int num,int head)
    :warrior(life)
    ,_num(num)
    ,_head(head)
    {
          _weapon=_num%3;
        if(_head==0)
            _morale=(double)totallife_red/life;
        else
        {
             _morale=(double)totallife_blue/life;
        }
        
        _head==0?_numOfDragon_red++:_numOfDragon_blue++;
    }
    void display_warrior()
    {   
        string weapon;
        if(_weapon==0)
            weapon="sword";
        else if(_weapon==1)
            weapon="bomb";
        else
            weapon="arrow";
        if(_head==0)
        cout<<"red dragon "<<_num<<" born with strength "<<getLife()<<","<<_numOfDragon_red<<" dragon in red"<<endl;
        else
        cout<<"blue dragon "<<_num<<" born with strength "<<getLife()<<","<<_numOfDragon_blue<<" dragon in blue"<<endl;

        cout<<"it has a "<<weapon;
        cout<<" and it's morale is"<<_morale<<endl;
    }
private:
    int _weapon;
    double _morale;
    int _num;
    static int _numOfDragon_blue;
    static int _numOfDragon_red;
    int _head;
};


int dragon::_numOfDragon_red=0;
int dragon::_numOfDragon_blue=0;

class ninja
:public warrior
{
public:
    ninja(int life,int num,int head)
    :warrior(life)
    ,_num(num)
    ,_head(head)
    {
          _weapon1=_num%3;
          _weapon2=(_num+1)%3;
      
        
        _head==0?_numOfninja_red++:_numOfninja_blue++;
    }
    void display_warrior()
    {   
        string weapon1;
        string weapon2;
        if(_weapon1==0)
            {weapon1="sword";weapon2="bomb";}
        else if(_weapon1==1)
            {weapon1="bomb";weapon2="arrow";}
        else
            {weapon1="arrow";weapon2="sword";}
        if(_head==0)
        cout<<"red ninja "<<_num<<" born with strength "<<getLife()<<","<<_numOfninja_red<<" ninja in red"<<endl;
        else
        cout<<"blue ninja "<<_num<<" born with strength "<<getLife()<<","<<_numOfninja_blue<<" ninja in blue"<<endl;
        printf("\033[33m                 |\n\033[0m");
        
        cout<<"it has a "<<weapon1;
        printf("\033[33m———|————————   \n\033[0m");
        printf("\033[33m                 |\n\033[0m");  
        cout<<"and a "<<weapon2<<endl; 
    }
private:
    int _weapon1;
    int _weapon2;
    int _num;
    static int _numOfninja_blue;
    static int _numOfninja_red;
    int _head;
};


int ninja::_numOfninja_red=0;
int ninja::_numOfninja_blue=0;




class iceman
:public warrior
{
public:
    iceman(int life,int num,int head)
    :warrior(life)
    ,_num(num)
    ,_head(head)
    {
          _weapon=_num%3;
        _head==0?_numOficeman_red++:_numOficeman_blue++;
    }
    void display_warrior()
    {   
        string weapon;
        if(_weapon==0)
            weapon="sword";
        else if(_weapon==1)
            weapon="bomb";
        else
            weapon="arrow";
        if(_head==0)
        cout<<"red iceman "<<_num<<" born with strength "<<getLife()<<","<<_numOficeman_red<<" iceman in red"<<endl;
        else
        cout<<"blue iceman "<<_num<<" born with strength "<<getLife()<<","<<_numOficeman_blue<<" iceman in blue"<<endl;
        cout<<"it has a "<<weapon<<endl;
    }
private:
    int _weapon;
    int _num;
    static int _numOficeman_blue;
    static int _numOficeman_red;
    int _head;
};

int iceman::_numOficeman_red=0;
int iceman::_numOficeman_blue=0;

class lion
:public warrior
{
public:
    lion(int life,int num,int head)
    :warrior(life)
    ,_num(num)
    ,_head(head)
    {
        if(_head==0)
            _loyal=totallife_red;
        else
        {
             _loyal=totallife_blue;
        }
        
        _head==0?_numOflion_red++:_numOflion_blue++;
    }
    void display_warrior()
    {   
        if(_head==0)
        cout<<"red lion "<<_num<<" born with strength "<<getLife()<<","<<_numOflion_red<<" lion in red"<<endl;
        else
        cout<<"blue lion "<<_num<<" born with strength "<<getLife()<<","<<_numOflion_blue<<" lion in blue"<<endl;
        cout<<" it's loyal is"<<_loyal<<endl;
    }
private:
    double _loyal;
    int _num;
    static int _numOflion_blue;
    static int _numOflion_red;
    int _head;
};

int lion::_numOflion_red=0;
int lion::_numOflion_blue=0;


class wolf
:public warrior
{
public:
    wolf(int life,int num,int head)
    :warrior(life)
    ,_num(num)
    ,_head(head)
    {   
        _head==0?_numOfwolf_red++:_numOfwolf_blue++;
    }
    void display_warrior()
    {   
        if(_head==0)
        cout<<"red wolf "<<_num<<" born with strength "<<getLife()<<","<<_numOfwolf_red<<" wolf in red"<<endl;
        else
        cout<<"blue wolf "<<_num<<" born with strength "<<getLife()<<","<<_numOfwolf_blue<<" wolfin blue"<<endl;
      
    }
private:
    int _num;
    static int _numOfwolf_blue;
    static int _numOfwolf_red;
    int _head;
};

int wolf::_numOfwolf_red=0;
int wolf::_numOfwolf_blue=0;



void print(warrior *w)
{
    w->display_warrior();
}
