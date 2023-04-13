#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>


int main(int argc, char *argv[]){
	int n;
	int text, output; 
	int fd1[2], fd2[2]; //two descripters for pipe
	char buf[10]; //read 10 characters
	
	text = open("myfile", 0); //open file for reading
	output = creat("outputFile", 0666); //create outputfile
	pipe(fd1);
	pipe(fd2);
	
	
	if(fork() == 0) { //child 1
		while((n=read(fd1[0], buf, 10)) != 0){
			for(int i = 0; i<10; i++)
				buf[i] = toupper(buf[i]); //convert into capital letters
			write(fd2[1], buf, n); //put into pipe2
		}
		close(fd1[0]);
		close(fd2[1]);
		exit(0);
	} else{
		if(fork() == 0){ //child 2
			while((n=read(fd2[0], buf, 10)) != 0){ //get data from pipe2
				write(output, buf, n); //put into output file
			}
			close(output);
			close(fd2[0]); //close unnecessary pipe channel
			wait(NULL);
		} else{ //parent
			close(fd1[0]); //close unnecessary pipe channel
			while((n = read(text, buf, 10)) != 0) //until EOF
				write(fd1[1], buf, n); //put into pipe1
			close(text);
			close(fd1[1]);
			exit(0);
		}
	} 	
}


