#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE	1024

int main(int argc, char *argv[]){
	int fdi, fdo;
	char buf[BUFFER_SIZE];
	ssize_t n;
	
	
	if((fdi = open("source.txt", O_RDONLY)) == -1) {
		perror(argv[1]);
		return 2;
	} //read only
	
	if((fdo = open("target.txt", O_WRONLY | O_CREAT | O_TRUNC | O_EXCL, S_IRUSR | S_IWUSR)) == -1){
		perror(argv[2]);
		return 3;
	}
	
	while((n = read(fdi, buf, 1)) > 0)
		write(fdo, buf, n);
		
	close(fdi);
	close(fdo);
	return 0;
}



