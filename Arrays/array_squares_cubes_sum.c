#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, ssquares = 0, scubes = 0;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nInitial Array Declaration:\n");
    for (i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }

    #pragma omp parallel for schedule(dynamic) shared(ssquares, scubes)
    for (i = 0; i < 9; i++){
        ssquares += pow(arr[i], 2);
        scubes += pow(arr[i], 3);
    }

    printf("\n\nSum of Squares in array: %d", ssquares);
    printf("\nSum of Cubes in array: %d\n", scubes);

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}

