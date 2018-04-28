#include <sudu/VerticalBlock.h>

VerticalBlock::VerticalBlock(int pos):BaseBlock(pos)
{
	init();
}

VerticalBlock::~VerticalBlock()
{
}

void VerticalBlock::init()
{
   for(int i=0;i<N;i++)
    {
        a[i]=&Controller::finalArray[nPos][i];
        la[i] = &Controller::data[nPos][i];
    }
}

bool VerticalBlock::checkover()
{
	int temp[9]={0};
	for(int i=0;i<N;i++)
    {
    	if(Controller::finalArray[nPos][i]==0)
        {
        	return false;
        }
        temp[Controller::finalArray[nPos][i]-1]++;  
    }
    for(int z=0;z<N;z++)
    {
        if(temp[z]!=1)
        {
            return false;
        }
    }
    return true;
}