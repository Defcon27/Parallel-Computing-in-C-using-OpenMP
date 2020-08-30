#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nInitial Array Declaration:\n");
    for (i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    #pragma omp parallel for ordered schedule(dynamic)
    for (i = 0; i < 5; i++){
        arr[i] = arr[i] * 5;
        arr[i] = arr[i] + 3;
    }

    printf("\n\nArray after construct\n");
    for (i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);

    return 0;
}
