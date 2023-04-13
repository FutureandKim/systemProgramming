#include <stdio.h>

#define BUFFER_SIZE	1024 //set buffer size

int main(int argc, char *argv[]){
	char ubuf[BUFFER_SIZE], fbuf[BUFFER_SIZE];
	int n;
	FILE *fpin, *fpout; //file pointer
	
	if(argc != 3){
		perror(argv[0]);
		return 1;
	}
	if((fpin = fopen(argv[1],"r"))==NULL){ //read file of argv[1]
		perror(argv[1]);
		return 2;
	}
	if((fpout = fopen(argv[2],"w"))==NULL){ //write file of argv[2]
		perror(argv[2]);
		return 2;
	}
	if(setvbuf(fpin, ubuf, _IOFBF, BUFFER_SIZE) != 0){ //full buffering
		perror("setvbuf(fpin)");
		return 4;
	}
	if(setvbuf(fpout, ubuf, _IOFBF, BUFFER_SIZE) != 0){ //full buffering
		perror("setvbuf(fpout)");
		return 4;
	}
	
	while( (n=fread(fbuf, sizeof(char), BUFFER_SIZE, fpin)) >0) 
		//read up to the size of buffer
		fwrite(fbuf, sizeof(char), n, fpout); //write
		
	fclose(fpin);
	fclose(fpout);
	return 0;
}


