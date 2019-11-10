#include "types.h"
#include "stat.h"
#include "user.h"


#include <stdlib.h>

/* Possible states of a thread; */
#define FREE        0x0
#define RUNNING     0x1
#define RUNNABLE    0x2

#define STACK_SIZE  8192
#define MAX_THREAD  4

typedef struct thread thread_t, *thread_p;
typedef struct mutex mutex_t, *mutex_p;

struct thread {
  int        sp;                /* curent stack pointer */
  char stack[STACK_SIZE];       /* the thread's stack */
  int        state;             /* running, runnable, waiting */
};
static thread_t all_thread[MAX_THREAD];
thread_p  current_thread;
thread_p  next_thread;
extern void thread_switch(void);
/*
 *
 *
 */
void 
thread_init(void)
{
  current_thread = &all_thread[0];
  current_thread->state = RUNNING;
}

static void 
thread_schedule(void)
{
  thread_p t;

  /* Find another runnable thread. */
  for (t = all_thread; t < all_thread + MAX_THREAD; t++) {
    if (t->state == RUNNABLE && t != current_thread) {
      next_thread = t;
      break;
    }
  }

  if (t >= all_thread + MAX_THREAD && current_thread->state == RUNNABLE) {
    /* The current thread is the only runnable thread; run it. */
    next_thread = current_thread;
  }

  if (next_thread == 0) {
    printf(2, "thread_schedule: no runnable threads\n");
    exit();
  }

  if (current_thread != next_thread) {         /* switch threads?  */
    next_thread->state = RUNNING;
    //thread_switch();//updaye current pointer, update status of currect to be runnable
  } else
    next_thread = 0;
}

void 
thread_create(void (*func)())
{
  thread_p t;

  for (t = all_thread; t < all_thread + MAX_THREAD; t++) {
    if (t->state == FREE) break;
  }
  t->sp = (int) (t->stack + STACK_SIZE);   // set sp to the top of the stack
  t->sp -= 4;                              // space for return address
  * (int *) (t->sp) = (int)func;           // push return address on stack
  t->sp -= 32;                             // space for registers that thread_switch will push
  t->state = RUNNABLE;
}

void 
thread_yield(void)
{
  current_thread->state = RUNNABLE;
  thread_schedule();
}

static void 
mythread(void)
{
  int i;
  printf(1, "my thread running\n");
  for (i = 0; i < 100; i++) {
    printf(1, "my thread 0x%x\n", (int) current_thread);
    thread_yield();
  }
  printf(1, "my thread: exit\n");
  current_thread->state = FREE;
  thread_schedule();
}


int 
main(int argc, char *argv[]) 
{

    printf(1,"matan1\n");

    const char* s = getenv("MYSET");
    printf("MYSET :%s\n",(s!=NULL)? s : "getenv returned NULL");
    thread_init();
    printf(1,"a2\n");
    thread_create(mythread);
    printf(1,"a3\n");
    thread_create(mythread);

    printf(1,"a4\n");
    //thread_schedule();

    printf(1,"a5\n");
    return 0;
}
