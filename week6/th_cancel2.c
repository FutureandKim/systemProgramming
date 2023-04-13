#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

int global;
void *printmsg(void *msg)
{
	int i=0;
	
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	
	while (i<10) {
		printf("%s : %d \n", (char *) msg, i++);
		sleep(1);
		if(i>5)
			pthread_testcancel();
	}
	
	pthread_exit((void *)pthread_self());
}

void main()
{
	pthread_t t1, t2, t3;
	
	void *rval1;
	void *rval2;
	
	int mydata;
	
	sleep(3);
	pthread_cancel(t1);
	pthread_create(&t1, NULL, printmsg, "Hello");
	pthread_create(&t2, NULL, printmsg, "World");
	
	
	pthread_join(t1, (void *)&rval1); //prdwait
	pthread_join(t2, (void *)&rval2);
	
	printf("t1: %lu, t2: %lu \n", t1, t2);
	printf("rval1: %lu, rval2: %lu \n", (unsigned long)rval1, (unsigned long)rval2);
}
