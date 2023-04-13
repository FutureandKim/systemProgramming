#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int global;
void *printmsg(void *msg)
{
	int i=0;
	while (i<5) {
		printf("%s : %d \n", (char *) msg, i++);
		sleep(1);
	}
	
	pthread_exit((void *)pthread_self());
}

void main()
{
	pthread_t t1, t2, t3;
	
	void *rval1;
	void *rval2;
	
	int mydata;
	
	pthread_create(&t1, NULL, printmsg, "Hello");
	pthread_create(&t2, NULL, printmsg, "World");
	
	sleep(3);
	pthread_cancel(t1);
	pthread_join(t1, (void *)&rval1); //prdwait
	pthread_join(t2, (void *)&rval2);
	
	printf("t1: %lu, t2: %lu \n", t1, t2);
	printf("rval1: %lu, rval2: %lu \n", (unsigned long)rval1, (unsigned long)rval2);
}

