#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9};
    int i, j, num, flag, primesum = 0;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nInitial Array Declaration:\n");
    for (i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }

    #pragma omp parallel for schedule(dynamic) shared(primesum, arr) private(num, j, flag)
    for (i = 0; i < 6; i++){
        num = arr[i];
        flag = 1;
        for (j = 2; j < num; j++){
            if (num % j == 0){
                flag = 0;
            }
        }
        if (flag == 1){
            #pragma omp critical
            primesum = primesum + num;
        }
    }

    printf("\n\nPrime Sum of array: %d", primesum);

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
