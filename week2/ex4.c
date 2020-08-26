#include <stdio.h> 
  
void swap(int *first, int *second) { 
    int swaper = *first; 
    *first = *second; 
    *second = swaper; 
} 
  
int main() 
{ 
    int first, second; 
    printf("Please enter 2 numbers to swap: \n");
    scanf("%d %d", &first, &second);
    swap(&first, &second); 
    printf("Here are your 2 numbers after swap: \n New first = %d. \n New second = %d.", first, second);
    return 0; 
}
