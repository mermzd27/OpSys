#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()

{   
    float a = FLT_MAX;
    int b = INT_MAX;
    double c = DBL_MAX;
    printf("%d, %d\n", b, sizeof(b));
    printf("%f, %d\n", a, sizeof(a));
    printf("%f, %d\n", c, sizeof(c));


    return 0;
}
