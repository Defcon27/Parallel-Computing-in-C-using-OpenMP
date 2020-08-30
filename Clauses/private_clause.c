#include <stdio.h>
#include <omp.h>

int main()
{
    int i=1;
    int j=2;

    printf("\nInitial declaration: i=%d j=%d",i,j);

    #pragma omp parallel private(i)
    {
        i=3;
        j=j+2;
        printf("\nInside construct: i=%d j=%d",i,j);
    }
    
    printf("\n\nOutside construct: i=%d j=%d",i,j);
    
    return 0;
}
