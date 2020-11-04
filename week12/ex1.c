#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>


int main(int argc, char *argv[]) {
	char myChar[21];									 
	myChar[20]='\0';
	FILE *myInp = fopen("/dev/random", "r");  	 	 
	if(myInp==NULL) {
		printf("File opening error\n");
	}		
	FILE *myOut = fopen("ex1.txt","w"); 
	if(myOut==NULL) {
		printf("File opening error\n");  
	}
	fread(myChar,1,20,myInp);						
	fputs(myChar,myOut);   								
	fclose(myOut);
}
