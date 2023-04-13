#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	char buf[100];
	char *arg[10];
	char *str;
	char *save;
	int argn;
	
	static const char tok[] = "\t\n"; 
	int pid;
	
	system("clear");
	
	while(1){
		printf(" [MyShell #] ");
		gets(buf); //one line
		argn = 0;
		
		str = strtok_r(buf, tok, &save);
		while(str != NULL){
			arg[argn++] = str;
			str = strtok_r(NULL, tok, &save);
		}
		arg[argn] = (char *)0;
		
		pid = fork();
		if (pid == 0){
			execvp(arg[0], arg); //argument array
		} else{
			pid = wait(NULL);
		}
	}
}










