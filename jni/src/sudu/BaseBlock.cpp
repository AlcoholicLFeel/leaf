#include <sudu/BaseBlock.h>
#include <log/logi.h>

BaseBlock::BaseBlock(int Pos)
{
    this->nPos = Pos;
}

BaseBlock::~BaseBlock()
{
}

bool BaseBlock::checkover()
{
	return false;
}

void BaseBlock::think()
{
    for(int i=0;i<9;i++)
    {
    	if((*(a[i]))!=0)
    	{
    		removeNum(*(a[i]));
    	}
    }
}

void BaseBlock::removeNum(int num)
{
    list<int>::iterator itor;
	  for(int i=0;i<9;i++)
	  {  
      for(itor=(*la[i]).begin();itor!=(*la[i]).end();itor++)
      {
        if(*itor==num)
        {
          (*(la[i])).erase(itor);
          break;
        }
      }
    }
}

bool BaseBlock::think1()
{

    int temp[9]={0};
    for(int i=0;i<9;i++)
    {
      if((*la[i]).size()>0)
      {
        for(list<int>::iterator itor=(*la[i]).begin();itor!=(*la[i]).end();itor++)
        {
          temp[*itor-1]++;
        }
      }
    }
    for(int i=0;i<9;i++)
    {
      if(temp[i]==1)
      {
          ensureNum(i+1);
          return true;
      }
    }
    return false;
}

void BaseBlock::ensureNum(int num)
{
    for(int i=0;i<9;i++)
    {
      for(list<int>::iterator itor=(*la[i]).begin();itor!=(*la[i]).end();itor++)
      {
        if(*itor==num)
        {
          (*(la[i])).clear();
          (*(la[i])).push_back(num);
          return;
        }
      }
    }
}