#include "types.h"
#include "stat.h"
#include "user.h"

#define STACK_SIZE  8192
#define MAX_THREAD  4

typedef struct thread thread_t, *thread_p;
struct thread {
    int        sp;                /* curent stack pointer */
    char stack[STACK_SIZE];       /* the thread's stack */
    int        state;             /* running, runnable, waiting */
};
static thread_t my_thread;
thread_p  my_thread_p;


extern void thread_switch(void);

void printNotZeros(){
    int s=0;
    for(int i=0;i<STACK_SIZE;i++)
        if (my_thread.stack[i]!=0)
            s++;
    printf(1,"nonzero is %d\n", s);
}

void
thread_create(void (*func)())
{
    thread_p t=my_thread_p;
    t->sp = (int) (t->stack + STACK_SIZE);   // set sp to the top of the stack
    t->sp -= 4;                              // space for return address
    * (int *) (t->sp) = (int)func;           // push return address on stack
    t->sp -= 32;

}


static void
afunc(void) {
    printf(1, "my thread running\n");
    printNotZeros();
}


int sum(int n){// return sum of 1-> n

    printf(1,"call sum, with n= %d\n", n);
    //print_esp_ebp();
    if (n==0){
        return 0;
    }
    return n+sum(n-1);

}
int
main(int argc, char *argv[])
{
    my_thread_p=&my_thread;
    for(int i=0;i<STACK_SIZE;i++)
        my_thread.stack[i]=0;
    printNotZeros();
    thread_create(afunc);
    printNotZeros();
    thread_switch();
    printf(1, "you dont want see me\n");
    return 0;
}
