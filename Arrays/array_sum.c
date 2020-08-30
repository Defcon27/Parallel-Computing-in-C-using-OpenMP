#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i, sum = 0;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nInitial Array Declaration:\n");
    for (i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    #pragma omp parallel for schedule(dynamic) shared(sum)
    for (i = 0; i < 5; i++){
        sum += arr[i];
    }

    printf("\n\nArray Sum after construct: %d\n", sum);

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);

    return 0;
}
