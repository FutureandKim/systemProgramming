#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


//prevent race condition
int main(int argc, char *argv[]){
	int fd[2];
	int pid;
	int read_fd, write_fd;
	int n;
	char buf;
	
	pipe(fd);
	
	pid = fork();
	if(pid == 0){
		read_fd = open("myfile", O_RDONLY);
		close(fd[0]);
		while((n=read(read_fd, &buf, 1)) != 0) {
			write(fd[1],&buf, 1);
		}
		close(read_fd);
		close(fd[1]);
		exit(0);
	} else{
		write_fd = creat("copyfile", 0666);
		close(fd[1]);
		while((n=read(fd[0], &buf, 1)) != 0) {
			write(write_fd, &buf, 1);
		}
		close(write_fd);
		close(fd[0]);
		wait(NULL);
	}

}
