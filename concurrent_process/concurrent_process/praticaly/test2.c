#include "pthread.h"
#include <stdio.h>
#define REPEAT 50000

long long int a = 0;

void check(){
    if(a != 1 && a != -1){
    printf("LONG LONG VALUE HAS BROKEN!!!");
    }
}

void *func(){
    int i;
    for(i=0;i<REPEAT;i++){
    a=1;
    check();
    }
    printf("SUB FINISHED");
}

int main(void){

    pthread_t pthread;
    pthread_create(&pthread,NULL,&func,NULL);
    int i;
    for(i=0;i<REPEAT;i++){
    a=-1;
    check();
    }
    pthread_join(pthread,NULL);
    printf("MAIN FINISHED");

    return 0;
}