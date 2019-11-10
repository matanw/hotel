#include "types.h"
#include "stat.h"
#include "user.h"

long int i1;
long int i2;
long int* p1;
long int *p2;

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
