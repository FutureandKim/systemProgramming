#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#define TMPFILE "mylog" 

static void myexit(void);
int main(void)
{
	FILE *fp;
	/*
	if (atexit(myexit) != 0) {
		perror("atexit error");
		exit(1);
	}
	*/
	
	
	if ((fp = fopen(TMPFILE, "a+")) == NULL) {
		perror("fopen error");
		exit(2);
	}
	
	for(int i = 0; i<100000;i++)
		fprintf (fp, "This is temporary log entry of pid %d\n", getpid());
	fclose (fp);
	exit(0);
}


static void myexit(void){
	if(unlink(TMPFILE)) {
		perror("myexit : unlink");
		exit(3);
	}
}
