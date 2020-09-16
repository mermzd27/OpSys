#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_NUMBER 6  

void *threadd(void *thread) {
 printf("this is thread %ld\n", (long)thread);
 pthread_exit(NULL);
}

int main() {
 pthread_t thread[THREADS_NUMBER];  
 for(int i = 0; i < THREADS_NUMBER; i++) {
     printf("creating thread %d\n", i);
     if(pthread_create(thread+i, NULL, threadd, (void *)i)) {
        printf("error");
          exit(EXIT_FAILURE);
     }
     if (pthread_join(thread[i], NULL)){
         printf("error");
         exit(EXIT_FAILURE);
     }
   }
   pthread_exit(NULL);
   exit(EXIT_SUCCESS);
}
