#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i;

    printf("\nPrinting array elements using ordered construct\n");
	#pragma omp parallel for ordered schedule(dynamic)
    for (i = 0; i < 5; i++)
    {
		#pragma omp ordered
        printf("%d ", arr[i]);
    }

    return 0;
}
