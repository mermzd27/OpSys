#include <stdio.h>

void bubbleSort(int array[], int numberOfElements);
int main() {
    
    int numberOfElements;
    printf("enter number of elements in array:\n");
    scanf("%d", &numberOfElements);

    int array[numberOfElements];
 
    printf("enter youe elements:\n");
    for (int i=0; i<numberOfElements; i=i+1){
            scanf("%d", &array[i]);
    }
    bubbleSort(array,numberOfElements);
    
    
    return 0;
}

void bubbleSort(int array[], int numberOfElements){
    int temp; 

     for(int i=0;i<numberOfElements-1;i++)
    {
        for(int j = 0;j<numberOfElements-i-1;j++)
        {
            if(array[j]>array[j+1]) 
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
              
     for (int i=0; i<numberOfElements; i=i+1){
            printf("%d\n", array[i]);
    }
}
