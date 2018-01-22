#include "pthread.h"
#include <stdio.h>

long long int a = 0;//64bit

void check(char expect){
	if(a != expect){
		printf("NON EXPECTED VALUE!");
	}
}

void *func(){
	int i;
	for(i = 0;i < 1000;i++){
		printf("[SUB]\n");
		a = 1;
		check(1);
	}
}

int main(void){
	pthread_t pthread;
	pthread_create(&pthread,NULL,&func,NULL);
	printf("start: a=%d\n", a);
	int i;
	for(i = 0;i < 1000;i++){
		printf("[MAIN]\n");
		a = -1;
		check(-1);
	}
	
	pthread_join(pthread,NULL);
	printf("end: a=%d\n", a);

	return 0;
}