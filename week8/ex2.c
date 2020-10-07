#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//when I run the command, I have notices that both si ans so didn't change, they were constantly 0, which means that my random access memory was enough to complete the process and there weas no need to to swaps.

int main() {
  for (int i = 0; i < 10; ++i) {
    void *pointer = malloc(10485760);//allocate 10 mb 
    memset(calloc(10485760,1), 0, 10485760); //fills with 0 allocated mem
    sleep(1); //sleeps for 1 sec
  }
    return 0;
}
