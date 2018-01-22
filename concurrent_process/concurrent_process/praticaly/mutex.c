#include "stdio.h"
#include "pthread.h"
#define REPEAT 50000000

pthread_mutex_t mutex;
long long int a = 0;

void check(){
	if(a != -1 && a != 1){
		printf("LOG LONG HAS BROKEN!");
	}
}

void *func_thread() {
  int i=0;
  for(i=0; i < REPEAT; i++){
    pthread_mutex_lock(&mutex);
    a = 1;
	check();
    pthread_mutex_unlock(&mutex);
  }
  printf("SUB FINISH");
}

int main(void) {
  pthread_mutex_init(&mutex, NULL);
  pthread_t pthread;
  pthread_create( &pthread, NULL, &func_thread,NULL);

  int i=0;
  for(i=0; i < 10000; i++){
    pthread_mutex_lock(&mutex);
    a =-1;
	check();
    pthread_mutex_unlock(&mutex);
  }

  pthread_join(pthread, NULL); 
  pthread_mutex_destroy(&mutex);
  printf("MAIN FINISH");

  return 0;
}