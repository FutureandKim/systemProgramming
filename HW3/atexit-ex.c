#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TMPFILE "mylog" //file

static void myexit(void); 

int main(void){
	FILE *fp;
	
	if(atexit(myexit) != 0){ //error
		perror("atexit error");
		exit(1);
	}
	
	if((fp = fopen(TMPFILE, "a+"))==NULL){ //file open
		perror("fopen error");
		exit(2);
	}
	fprintf(fp, "This is temporary log entry of pid %d\n", getpid()); //log
	
	fclose(fp); //file close
	exit(0);
}

static void myexit(void){
	if(unlink(TMPFILE)){ //unlink and delete file
		perror("myexit : unlink");
		exit(3);
	}
}


