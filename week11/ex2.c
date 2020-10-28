#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IOLBF, 128);
	char *myText = "Hello";
	for(int i = 0; i < 5; i++) {
		printf("%c",myText[i]);
		sleep(1);
	}
	return 0;
}
