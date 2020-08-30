#include <stdio.h>
#include <omp.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[4];
    int i;

    printf("\nInitial Declaration:\n");
    for (i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }

    #pragma omp parallel
    {
        #pragma omp for lastprivate(i)
        for (i = 0; i < 4; i++)
        {
            b[i]=a[i]=a[i+1];
        }
    }

    printf("\nArray after construct: \n");
    for (i = 0; i < 4; i++){
        printf("%d ", b[i]);
    }

    return 0;
}
