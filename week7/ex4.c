#include <stdlib.h>
#include <stdio.h>
#include <time.h>  
#include <string.h>

void* reallocFunc(void* pointerToArray, size_t new) {
	void *newPointerToArray = malloc(new);
	if (pointerToArray == NULL) {
		return newPointerToArray;
	}
	if (new == 0) {
		free(pointerToArray);
		return NULL;
	}
	size_t size = ((size_t*)pointerToArray)[-1];
	memcpy(newPointerToArray, pointerToArray, (size < new ? size : new));
}

//below is a code from ex.3

int main(){
    srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

    reallocFunc(a1, n2*sizeof(int));
    
    if(n2>n1){
        for (int i=n1;i<n2;i++){
            a1[i]=0;
        }
        
    }
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");
	return 0;
}
