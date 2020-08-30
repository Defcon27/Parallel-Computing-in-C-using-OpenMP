#include <stdio.h>
#include <omp.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int i = 1;

    printf("\nInitial declaration: Sum is %d", sum);

    #pragma omp parallel shared(sum)
    {
        #pragma omp for
        for (i = 0; i < 5; i++)
        {
            sum = sum + a[i];
        }
    }

    printf("\n\nOutside construct: Sum is %d", sum);

    return 0;
}
