#include <wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int res, pid;
	int status;
	
	res = fork();
	
	if(res==0){
		printf("child process\n");
		sleep(3);
		exit(77);
	} else {
		printf("parent, child process = %d\n", res);
		pid = wait(&status);
		sleep(5);
		printf("The child %d is exited with %d \n", pid, WEXITSTATUS(status));
	}
}
