#include <sudu/RectBlock.h>

RectBlock::RectBlock(int Pos):BaseBlock(Pos)
{
	row = nPos/3;
    ver = nPos%3;
    init();
}

RectBlock::~RectBlock()
{
}

void RectBlock::init()
{
    int current=0;
    for(int i=0+ver*3;i<=2+ver*3;i++)
    {
    	for(int j=0+row*3;j<=2+row*3;j++)
    	{
            a[current]=&Controller::finalArray[i][j];
            la[current]=&Controller::data[i][j];
            current++;
        }
    }
}

bool RectBlock::checkover()
{
	int temp[9]={0};
    for(int i=0+ver*3;i<=2+ver*3;i++)
    {
        for(int j=0+row*3;j<=2+row*3;j++)
        {
        	if(Controller::finalArray[i][j]==0)
        	{
        		return false;
        	}
            temp[Controller::finalArray[i][j]-1]++; 
        }
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