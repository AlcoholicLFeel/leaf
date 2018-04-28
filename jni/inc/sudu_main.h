#ifndef SUDU_MAIN_H
#define SUDU_MAIN_H
#include "main.h"

#include <sudu/BaseBlock.h>
#include <sudu/RectBlock.h>
#include <sudu/VerticalBlock.h>
#include <sudu/HorizontalBlock.h>
#include <sudu/Controller.h>


class sudu_main
{
    public:
        void init();
        void print();
        void setMemberTest();
        void work();
        void setMember(int i_hor,int i_ver,int i_num);
        static int finalArray[N][N];
        static list<int> data[N][N];
    protected:
    private:
        void flush();
        int getfinishnum();
        bool checkover(list<BaseBlock*>);
        list<BaseBlock*> init_vector();
        void dothink(list<BaseBlock*>);
        int dothink1(list<BaseBlock*>,int i);
        bool dowork(list<BaseBlock*>);
        bool doenum(list<BaseBlock*>);
        void sudu_backup();
        void sudu_reduction();
        int count =0;
};


#endif
