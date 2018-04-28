#ifndef SUDU_HORIZONTALBLOCK_H
#define SUDU_HORIZONTALBLOCK_H
#include "BaseBlock.h"

class HorizontalBlock:public BaseBlock
{
    public:
        HorizontalBlock(int Pos);
        ~HorizontalBlock();
        bool checkover();
    protected:
    private:
    	void init();
};

#endif
