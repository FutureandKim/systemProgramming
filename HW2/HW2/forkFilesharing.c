#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;
	int n;
	int pid1, pid2;
	char buf[10]; //read 10 characters
	
	fd = open("myfile", O_RDONLY);
	
	pid1 = fork(); //first fork
	
	if(pid1 == 0){ //child 1
		while((n=read(fd, buf, 10)) != 0){ //until EOF
			printf("pid: %d, character: %s\n", getpid(), buf); //print pid, character
			sleep(1);
		}
		exit(0);
	} else {
		pid2 = fork(); //second fork
		if(pid2 == 0){ //child 2
			while((n=read(fd, buf, 10)) != 0){ //until EOF
				printf("pid: %d, character: %s\n", getpid(), buf); //print pid, character
				sleep(1);
			}
			exit(0);
		} else { //parent
			while((n=read(fd, buf, 10)) != 0){ //until EOF
				printf("pid: %d, character: %s\n", getpid(), buf); //print pid, character
				sleep(1);
			}
			wait(NULL); //wait for the deaths of child process
			wait(NULL); //wait for the deaths of child process
			exit(0);
		}
	}
}


