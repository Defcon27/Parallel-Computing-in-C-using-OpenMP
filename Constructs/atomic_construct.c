#include <stdio.h>
#include <omp.h>

int main()
{
    int x[5] = {1,0,0,0,0};
    int i;

    printf("\nInitial Declaration:\n");
    for (i = 0; i < 5; i++){
        printf("%d ", stack[i]);
    }

    #pragma omp parallel for shared(x)
    for(i = 0; i < 5; i++)
    {
        #pragma omp atomic write
        x[i] = x[0]*2*i;
    }

    printf("\nArray after construct: \n");
    for (i = 0; i < 5; i++){
        printf("%d ", x[i]);
    }
    return 0;
}
