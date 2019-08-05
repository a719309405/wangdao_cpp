#include"wowperson.h"

// dra nin ice lion wolf
//ice lion wolf ninja dra 
//lion dragon ninja iceman wolf
void test()
{
    cout<<"totallife:"<<endl;
    cin>>totallife_red;
    totallife_blue=totallife_red;
    int min=65535;//min life;
    for(int i=0;i<5;i++)
    {
        cin>>lifearry[i];
        if (min>lifearry[i])
            {min=lifearry[i];}
    }
    cout<<"min:"<<min<<endl;
    int endofred=1;
    int endofblue=1;
    int i=0,j=0;
    while(endofred||endofblue)
    {
        if(endofred)
        {
            printf("%03d ",mytime);
            if(totallife_red<min)
            {
                cout<<"red head stops making warriors (life) "<<endl;endofred=0;
            }
            else if(mytime==5)
            {
                cout<<"red head stops making warriors (time) "<<endl;endofred=0;
            }
            else
            {
                int flag=1;
                num_red++;
                while(flag)
                {
                    switch(i)
                    {
                        case 0:
                        if(totallife_red>=lifearry[2])
                            {totallife_red-=lifearry[2];iceman ice(lifearry[2],num_red,0);print(&ice);flag=0;break;}
                        case 1:
                        if(totallife_red>=lifearry[3])
                            {totallife_red-=lifearry[3];lion li(lifearry[3],num_red,0);print(&li);flag=0;break;}    
                        case 2:
                        if(totallife_red>=lifearry[4])
                            {totallife_red-=lifearry[4];wolf wol(lifearry[4],num_red,0);print(&wol);flag=0;break;}
                        case 3:
                        if(totallife_red>=lifearry[1])
                            {totallife_red-=lifearry[1];ninja nin(lifearry[1],num_red,0);print(&nin);flag=0;break;}
                        case 4:
                        if(totallife_red>=lifearry[0])
                            {totallife_red-=lifearry[0];dragon dra(lifearry[0],num_red,0);print(&dra);flag=0;break;}
                    }
                        i=(i+1)%5;
                }
            }
        }
        if(endofblue)
        {
            printf("%03d",mytime);
            if(totallife_blue<min)
            {
                cout<<"blue head stops making warriors (life) "<<endl;endofblue=0;
            }
            else if(mytime==10)
            {
                cout<<"blue head stops making warriors (time) "<<endl;endofblue=0;
            }
            else
            {
                int flag=1;
                num_blue++;
                while(flag)
                {//lion dragon ninja iceman wolf
                    switch(j)
                    {
                        case 0:
                        if(totallife_blue>=lifearry[3])
                            {totallife_blue-=lifearry[3];lion li(lifearry[3],num_blue,1);print(&li);flag=0;break;}  
                         case 1:
                        if(totallife_blue>=lifearry[0])
                            {totallife_blue-=lifearry[0];dragon dra(lifearry[0],num_blue,1);print(&dra);flag=0;break;}
                        case 2:
                        if(totallife_blue>=lifearry[1])
                            {totallife_blue-=lifearry[1];ninja nin(lifearry[1],num_blue,1);print(&nin);flag=0;break;}
                        case 3:
                        if(totallife_blue>=lifearry[2])
                            {totallife_blue-=lifearry[2];iceman ice(lifearry[2],num_blue,1);print(&ice);flag=0;break;}        
                        case 4:
                        if(totallife_blue>=lifearry[4])
                            {totallife_blue-=lifearry[4];wolf wol(lifearry[4],num_blue,1);print(&wol);flag=0;break;}
                        
                    }
                        j=(j+1)%5;
                        //cout<<j<<"  "<<flag<<endl;
                }
            }
        }
        mytime++;
    }
   
}
int main()
{
    test();
    return 0;
}

