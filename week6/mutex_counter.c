#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>



void *Incrementer();
void *Decrementer();
int counter = 10000 ;
 
pthread_mutex_t mVar = PTHREAD_MUTEX_INITIALIZER;

int main(){
	pthread_t ptid, ctid;
	pthread_mutex_init(&mVar, NULL) ;
	
	pthread_create(&ptid,NULL,Incrementer,NULL);
	pthread_create(&ctid,NULL,Decrementer,NULL);
	pthread_join(ptid,NULL);
	pthread_join(ctid,NULL);
	
	pthread_mutex_destroy(&mVar);
	return 0;
}

void *Incrementer(){ 
	for(;;) {
		//pthread_mutex_lock(&mVar);
		counter++ ;
		printf("Inc : %d \n", counter);
		sleep(1);
		//pthread_mutex_unlock(&mVar);
	}
}
void *Decrementer()
{ 
	for(;;) {
		//pthread_mutex_lock(&mVar);
		counter-- ;
		printf("Dec : %d \n", counter);
		sleep(1);
		//pthread_mutex_unlock(&mVar);
	}
}

