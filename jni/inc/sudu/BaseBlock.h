#ifndef SUDU_BASEBLOCK_H
#define SUDU_BASEBLOCK_H
#include <main.h>
#include "Controller.h"

class BaseBlock
{
    public:
        BaseBlock(int Pos);
        ~BaseBlock();
        void addMember(list<int> Member);
        void think(); 
        bool think1();
        virtual bool checkover();
    protected:
        int nPos;
        int* a[N];
        list<int>* la[N];
        
    private:
    	void removeNum(int Num);
        void ensureNum(int Num);
};


#endif
