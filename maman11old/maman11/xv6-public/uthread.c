#include "types.h"
#include "stat.h"
#include "user.h"

long int esp_var;
long int bsp_var;
long int* esp_point;
long int* bsp_point;




extern void thread_switch(void);

int 
main(int argc, char *argv[]) 
{

    esp_point=&esp_var;
    bsp_point= &bsp_var;
    thread_switch();
    printf(1, "bsp:%d , esp:%d\n",bsp_var,esp_var);
    return 0;
}
