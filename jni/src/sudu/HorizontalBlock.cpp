#include <sudu/HorizontalBlock.h>

HorizontalBlock::HorizontalBlock(int pos):BaseBlock(pos)
{
    init();
}

HorizontalBlock::~HorizontalBlock()
{
}

void HorizontalBlock::init()
{
    for(int i=0;i<N;i++)
    {
        a[i]=&Controller::finalArray[i][nPos];
        la[i] = &Controller::data[i][nPos];
    }
}

bool HorizontalBlock::checkover()
{
	int temp[9]={0};
    for(int j=0;j<N;j++)
    {
    	if(Controller::finalArray[j][nPos]==0)
        {
        	return false;
        }
       temp[Controller::finalArray[j][nPos]-1]++;  
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
