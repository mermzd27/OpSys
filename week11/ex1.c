#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	const char *myString = "This is a nice day";
	int myFile = open("ex1.txt", O_RDWR);
	size_t mySize = strlen(myString);
	ftruncate(myFile, mySize); 
	char *myMap = mmap(NULL, mySize, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, myFile, 0); 
	for(size_t i = 0; i < mySize; i++) {
		myMap[i] = myString[i];
	}
	close(myFile);

	return 0;
}
