#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char buf[256];
	int rspn;
	long pos;
	
	//open file in read mode (offset = 0)
	if((fp=fopen(argv[1], "r"))==NULL){ 
		perror(argv[1]);
		return 1;
	}
	rspn = fseek(fp, 8L, SEEK_SET);
	pos = ftell(fp); //pos = 8
	
	fgets(buf, 256, fp); //read file from 8
	printf("Position : %ld\n",pos); //pos = 8
	printf("%s\n", buf); //print 256 from 8
	
	rewind(fp); //pos = 0
	pos = ftell(fp);
	
	fgets(buf, 256, fp); //read file from 0
	fclose(fp);
	printf("Position : %ld\n", pos); // pos = 0
	printf("%s\n", buf); //print 256 from 0
	return 0;
}
