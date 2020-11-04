#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

int myTee(int append, char *myFile) {
	int mySize = 1024;
	int mySize1;
	char myChar[mySize];
	memset(myChar,0,mySize);
	FILE *myOut;
	if(append==1) {
		myOut=fopen(myFile,"a");
	}
	else {
        myOut=fopen(myFile,"w");
    }
    if(myOut==NULL) {
    	printf("File opening error");
		return 1;
    }
    while((mySize1=read(0,myChar,mySize))>0) {
    	fprintf(myOut, "%s", myChar);
    	memset(myChar, 0, mySize);
    }
    if(mySize1<0) {
    	printf("File reading error");
		return 1;
    }
    fclose(myOut);
    return 0;
}

int main(int argc, char *argv[]) {
	int append = 0;
	char *myFile;
	if(argc<2) {
		printf("usage: %s [-a] <filename>…​\n", argv[0]);
		return 1;
	}
	if(argc==2) {
		myFile = argv[1];
	}
	else {
		append = 1 + !(bool)(strcmp(argv[1], "-a"));	
		myFile = argv[2];
	}

	return myTee(append,myFile);
}
