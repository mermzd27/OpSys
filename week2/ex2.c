#include <stdio.h>
#include <string.h>
int main()

{   
    char stringToRead[100];
    char reversedString[100];
    
    printf("write your string");
    fgets(stringToRead, sizeof(stringToRead), stdin);
    int a= strlen(stringToRead);
    
   // printf(stringToRead);
    
    for ( int i=(a-1); i>=0; i--){ 
        
        printf("%c", stringToRead[i]);
    
    }

    return 0;
}
