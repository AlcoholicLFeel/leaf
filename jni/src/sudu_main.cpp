#include <sudu_main.h>

int sudu_main::finalArray[N][N];
list<int> sudu_main::data[N][N];

void sudu_main::init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            Controller::finalArray[i][j]=0;
            for(int z=1;z<=N;z++)
            {
                Controller::data[i][j].push_front(z);
            }
        }
    }
}

void sudu_main::print()
{
    /*cout<<"=====================m_data"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<"\t";
            for(list<int>::iterator itor=Controller::data[i][j].begin();itor!=Controller::data[i][j].end();itor++)
            {
                cout<<*itor;
            } 
        }
        cout<<endl;
    }*/
    cout<<"======================  "<<++count<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<Controller::finalArray[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void sudu_main::setMemberTest()
{
    setMember(1,2,5);
    setMember(1,4,6);
    setMember(2,7,7);
    setMember(2,8,3);
    setMember(3,4,1);
    setMember(4,5,7);
    setMember(4,7,8);
    setMember(5,2,6);
    setMember(5,8,5);
    setMember(6,1,1);
    setMember(7,1,7);
    setMember(7,5,4);
    setMember(7,7,2);
    setMember(8,3,4);
    setMember(8,5,3);
    setMember(9,4,5);
    setMember(9,8,6);
    /*setMember(1,5,1);
    setMember(1,8,5);
    setMember(1,9,4);
    setMember(2,2,8);
    setMember(2,3,3);
    setMember(4,1,7);
    setMember(4,4,6);
    setMember(4,7,3);
    setMember(5,1,4);
    setMember(5,3,1);
    setMember(6,6,2);
    setMember(6,7,9);
    setMember(7,2,2);
    setMember(7,7,8);
    setMember(8,4,4);
    setMember(8,5,5);
    setMember(9,4,1);*/
    /*setMember(1,1,8);
    setMember(1,7,6);
    setMember(1,8,1);
    setMember(2,4,4);
    setMember(2,7,5);
    setMember(4,1,2);
    setMember(4,5,7);
    setMember(4,6,1);
    setMember(5,3,8);
    setMember(5,7,4);
    setMember(6,5,2);
    setMember(7,2,5);
    setMember(7,8,2);
    setMember(7,9,7);
    setMember(8,3,4);
    setMember(8,4,6);
    setMember(9,2,3);*/
}

void sudu_main::setMember(int i_hor,int i_ver,int i_num)
{
    Controller::finalArray[i_hor-1][i_ver-1]=i_num;
    Controller::data[i_hor-1][i_ver-1].clear();
}

void sudu_main::work()
{
    list<BaseBlock*> hor = init_vector();
    if(dowork(hor))
    {
        checkover(hor);
    }
    else
    {
        doenum(hor);
    }
}

bool sudu_main::doenum(list<BaseBlock*> hor)
{
    sudu_backup();
    list<int>::iterator itor;
    list<int> temp;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            temp.clear();
            if(Controller::data[i][j].size()!=0)
            {
                for(itor=Controller::data[i][j].begin();itor!=Controller::data[i][j].end();itor++)
                {
                    temp.push_front(*itor);
                }
            }
            if(temp.size()!=0)
            {
                for(itor=temp.begin();itor!=temp.end();itor++)
                {
                    setMember(i+1,j+1,*itor);
                    if(dowork(hor))
                    {
                        if(checkover(hor))
                        {
                            return true;
                        }
                        else
                        {
                            sudu_reduction();
                        }
                    }
                    else
                    {
                        sudu_reduction();
                    }
               }
            }
        }
    }
    return false;
}

void sudu_main::sudu_backup()
{
    list<int>::iterator itor;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            sudu_main::finalArray[i][j]=Controller::finalArray[i][j];
            for(itor=Controller::data[i][j].begin();itor!=Controller::data[i][j].end();itor++)
            {
                sudu_main::data[i][j].push_front(*itor);
            }
        }
    }
}

void sudu_main::sudu_reduction()
{
    list<int>::iterator itor;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            Controller::finalArray[i][j]=sudu_main::finalArray[i][j];
            Controller::data[i][j].clear();
            for(itor=sudu_main::data[i][j].begin();itor!=sudu_main::data[i][j].end();itor++)
            {
                Controller::data[i][j].push_front(*itor);
            }
        }
    }
}

bool sudu_main::dowork(list<BaseBlock*> hor)
{
    int iJudge=0;
    while(1)
    {   
        dothink(hor);
        flush();
        if(iJudge==getfinishnum())
        {
            iJudge=dothink1(hor,iJudge);
            if(iJudge==getfinishnum())
            {
                return false;
            }
            flush();
        }
        if(getfinishnum()==81)
        {
            return true;
        }
        iJudge = getfinishnum();
    }
}


list<BaseBlock*> sudu_main::init_vector()
{
    list<BaseBlock*> hor;
    for(int i=0;i<N;i++)
    {
        HorizontalBlock* Horizontal = new HorizontalBlock(i);
        VerticalBlock*   Vertical = new VerticalBlock(i);
        RectBlock*       Rect = new RectBlock(i); 
        hor.push_front(Horizontal);
        hor.push_front(Vertical);
        hor.push_front(Rect);
    }
    return hor;
} 

void sudu_main::dothink(list<BaseBlock*> hor)
{
    list<BaseBlock*>::iterator itor;
    itor = hor.begin();  
    while(itor!=hor.end())  
    {   
        (*itor)->think();
        itor++; 
    } 
}

int sudu_main::dothink1(list<BaseBlock*> hor,int iJudge)
{
    list<BaseBlock*>::iterator itor;
    itor = hor.begin(); 
    while(itor!=hor.end())  
    {   
        if((*itor)->think1())
        {
            return 0;
        }
        itor++; 
    }
    return iJudge;
}

bool sudu_main::checkover(list<BaseBlock*> hor)
{
    list<BaseBlock*>::iterator itor = hor.begin();  
    while(itor!=hor.end())  
    {   
        if(!(*itor)->checkover())
        {
            return false;
        }
        itor++; 
    }
    return true;
}

void sudu_main::flush()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Controller::data[i][j].size()==1)
            {
                setMember(i+1,j+1,*(Controller::data[i][j].begin()));
            }
        }
    }
    print();
}

int sudu_main::getfinishnum()
{
    int count = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Controller::finalArray[i][j]!=0)
            {
                count++;
            }
        }
    }
    return count;
}
