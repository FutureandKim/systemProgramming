#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int pid;
	int fd1, fd2;
	int n;
	char buf;
	

	fd1 = open("myfile", O_RDONLY);
	fd2 = creat("copyfile", 0666);
	for (int i = 0; i<5;i++)
		fork();
	
	while ((n=read(fd1, &buf, 1)) != 0)	
		write(fd2, &buf, 1);
	close(fd1);
	close(fd2);
}
