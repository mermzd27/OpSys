#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int *array;
    int numberOfElements = 0;
    printf("enter the number of elements in your array:");
    scanf("%d",&numberOfElements); 
    array = (int *)malloc(numberOfElements * sizeof(int));
    for (int i =0; i < numberOfElements; i++)
    {
        array[i] = i;
    }
    for (int i =0; i < numberOfElements; i++)
    {
        printf("\narray[%d] = %d\n", i,array[i]);
    }
    
    free(array);
	exit(EXIT_SUCCESS);
}
