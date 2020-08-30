#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, e = 0, o = 0;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nInitial Array Declaration:\n");
    for (i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    #pragma omp parallel for schedule(dynamic) shared(e, o)
    for (i = 0; i < 10; i++){
        if (arr[i] % 2 == 0)
            e++;
        else
            o++;
    }

    printf("\n\nEven numbers in array: %d", e);
    printf("\nOdd numbers in array: %d\n", o);

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
