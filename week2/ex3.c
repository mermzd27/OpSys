#include <stdio.h>
int main() {
    int height,emp=0;
    scanf("%d",&height);
    int width=0;
    for (int i=1; i<=height; i++) {
      width = 0;
      for (emp=1; emp<=height-i; emp++) {
         printf("  ");
      }
      while (width!=(2*i)-1) {
         printf("* ");
         width++;
      }
      printf("\n");
    }
    return 0;
}
