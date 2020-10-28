#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int myFile = open("ex1.txt", O_RDONLY);
	int myNewFile = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0777);
	size_t mySize = lseek(myFile, 0, SEEK_END);
	ftruncate(myNewFile, mySize); 
	char *myMap = mmap(NULL, mySize, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, myFile, 0); 
	char *myNewMap = mmap(NULL, mySize, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, myNewFile, 0); 
	memcpy(myNewMap, myMap, mySize);
	close(myFile);
	close(myNewFile);

	return 0;
}
