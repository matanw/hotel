#include "types.h"
#include "stat.h"
#include "user.h"

int i1;
int i2;
int* p1;
int *p2;

extern void thread_switch(void);

int 
main(int argc, char *argv[]) 
{
    i1=11;
    p1=&i1;
    p2= &i2;
    thread_switch();
    printf(1, "i2:%d\n",i2);
    return 0;
}
