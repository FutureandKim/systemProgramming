#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	struct stat statbuf; 
	
	if(argc!=3){
		perror("argument error");
		return 1;
	}
	if(!strcmp(argv[1], "stat")){ //compare
		if(stat(argv[2], &statbuf) < 0) { //get statbuf
			perror("stat");
			return 2;
		}
	}
	else if(!strcmp(argv[1], "fstat")){ //if fstat
		int filedes = open(argv[2], O_RDWR); //get file descriptor
		if(fstat(filedes, &statbuf) < 0) {
			perror("stat");
			return 3;
		}
	}
	else if(!strcmp(argv[1], "lstat")) { //if lstat(if symbloic link)
		if(lstat(argv[2], &statbuf)<0){ //get statbuf
			perror("lstat");
			return 4;
		}
	}
	
	//print type of the file
	if(S_ISREG(statbuf.st_mode)) 
		printf("%s is Regular File\n", argv[2]);
	if(S_ISDIR(statbuf.st_mode))
		printf("%s is Directory\n", argv[2]);
	if(S_ISLNK(statbuf.st_mode))
		printf("%s is Link File\n", argv[2]);
}


