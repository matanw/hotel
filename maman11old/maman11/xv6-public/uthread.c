#include "types.h"
#include "stat.h"
#include "user.h"

long int esp_var;
long int ebp_var;
long int* esp_point;
long int* ebp_point;




extern void thread_switch(void);

void print_esp_ebp(){

    thread_switch();
    printf(1, "ebp:%d , esp:%d - Hex: ebp:%x , esp:%x\n ",ebp_var,esp_var,ebp_var,esp_var);
}
int sum(int n){// return sum of 1-> n

    printf(1,"call sum, with n= %d\n", n);
    print_esp_ebp();
    if (n==0){
        return 0;
    }
    return n+sum(n-1);

}

void f1(){
    printf(1,"f1 call");
    print_esp_ebp();
    f2();

}
void f2(){
    printf(1,"f2 call");
    print_esp_ebp();
    f3();

}
void f3(){
    printf(1,"f3 call");
    print_esp_ebp();
}
int
main(int argc, char *argv[]) 
{

    esp_point=&esp_var;
    ebp_point= &ebp_var;
    print_esp_ebp();
    int s=sum(5);

    printf(1,"sum is %d\n", s);
    f1();
    return 0;
}


