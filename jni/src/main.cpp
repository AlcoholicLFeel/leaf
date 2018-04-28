#include <main.h>
#include <sudu_main.h>

int main(int argc,char **argv)
{
    sudu_main a;
    a.init();
 //   a.print();
    a.setMemberTest();
    a.print(); 
    a.work();
    a.print();
}
