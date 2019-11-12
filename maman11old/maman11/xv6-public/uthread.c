#include "types.h"
#include "stat.h"
#include "user.h"

long int esp_var;
long int ebp_var;
long int* esp_point;
long int* ebp_point;




extern void thread_switch(void);

int 
main(int argc, char *argv[]) 
{

    esp_point=&esp_var;
    epb_point= &ebp_var;
    thread_switch();
    printf(1, "epp:%d , esp:%d\n",ebp_var,esp_var);
    return 0;
}
