#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int res, pid;
	int status;
	
	res = fork();
	
	if(res == 0){
		printf("child process\n");
		exit(77);
	} else {
		pid = wait(&status);
		printf("the child %d is exited with %d\n", pid, WEXITSTATUS(status));
	}
}
