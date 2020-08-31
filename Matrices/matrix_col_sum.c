#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int col_sum[3];
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

    omp_set_num_threads(5);
	#pragma omp parallel for shared(col_sum)
    for (i = 0; i < 3; i++){
        col_sum[i] = 0;
        for (j = 0; j < 3; j++){
            col_sum[i] += mat[j][i];
        }
    }

    printf("\nColumn sum of Matrix\n");
    for (i = 0; i < 3; i++){
        printf("%d\n", col_sum[i]);
    }

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
