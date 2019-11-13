#include "types.h"
#include "stat.h"
#include "user.h"

long int esp_var;
long int ebp_var;
long int* esp_point;
long int* ebp_point;
#definde PRINT_REGISTERS  thread_switch(); \
   printf(1, "ebp:%d , esp:%d - Hex: ebp:%x , esp:%x\n ",ebp_var,esp_var,ebp_var,esp_var);



extern void thread_switch(void);

int sum(int n){// return sum of 1-> n

    printf(1,"call sum, with n= %d\n", n);
    PRINT_REGISTERS
    if (n==0){
        return 0;
    }
    return n+sum(n-1);

}

void f3(){
    printf(1,"f3 call\n");
    PRINT_REGISTERS
}

void f2(){
    printf(1,"f2 call\n");
    PRINT_REGISTERS
    f3();

}
void f1(){
    printf(1,"f1 call\n");
    PRINT_REGISTERS
    f2();

}
int
main(int argc, char *argv[]) 
{

    esp_point=&esp_var;
    ebp_point= &ebp_var;
    PRINT_REGISTERS
    int s=sum(5);

    printf(1,"sum is %d\n", s);
    f1();
    return 0;
}


