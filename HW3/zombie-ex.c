#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	pid_t	pid;
	int i = 10000;
	
	if((pid = fork()) < 0) { //error
		perror("fork error");
	} else if(pid == 0) { //from child process to daemon process
		printf("Child: pid %d\n", getpid());
		
		while(1){
			printf("c(%d)\n", i);
			i++;
			sleep(1);
		}
	} else { //parent process
		printf("Parent: pid=%d\n", getpid());
		printf("Parent: Child pid=%d\n", pid);
		
		sleep(1);
		printf("parent: exit\n");
		exit(0);
	}
}



