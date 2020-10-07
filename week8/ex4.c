#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    struct rusage *usage = malloc(sizeof(struct rusage)); //allocate memory
    int who=RUSAGE_SELF;
    int mb=10485760; //10 megabytes
    for (int i=0;i<10;i++){
        memset(calloc(10485760,1),0,10485760);
        if(getrusage(who,usage)){
            printf("occured error: %p\n", strerror(errno)); //to detect error occured
        };
        printf("ru_maxrss: %ld\n", (*usage).ru_maxrss);
        sleep(1);
    }
    return 0;
}
