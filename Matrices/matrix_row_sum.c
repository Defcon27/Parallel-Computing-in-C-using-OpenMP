#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row_sum[3];
    int i, j;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("Matrix Declarations:\nMatrix\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    omp_set_num_threads(15);
	#pragma omp parallel for shared(row_sum)
    for (i = 0; i < 3; i++){
        row_sum[i] = 0;
        for (j = 0; j < 3; j++){
            row_sum[i] += mat[i][j];
        }
    }

    printf("\nRow sum of Matrix\n");
    for (i = 0; i < 3; i++){
        printf("%d ", row_sum[i]);
    }

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
