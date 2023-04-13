#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	int i = 10000;
	if ((pid = fork()) < 0) {
		perror("fork error");
	} 
	else if (pid == 0) { /* child process  daemon */
		printf("Child: pid=%d\n",getpid());
		while(1) {	
			printf("c(%d)\n",i);
			i++;
			sleep(1);
			printf("Child process : pid = %d, ppid = %d, pgrp = %d, pgid = %d\n" getpid(), getppid(), getpgrp(), getpgid(getpid()));
		if(i>10)
			exit(0);
		} 
	}
	else { /* parent process */
		printf("Parent: pid=%d\n",getpid());
		printf("Parint: Child pid=%d\n",pid);
		while(1){
			sleep(1);
		}
		
		printf("Parent : exit\n");
		exit(0);
	}
}
