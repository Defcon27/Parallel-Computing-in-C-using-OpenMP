#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int sum[3][3];
    int i, j, k;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("Matrix Declarations:\nMatrix 1\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    
    omp_set_num_threads(5);
    #pragma omp parallel for
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            sum[i][j] = 0;
            for (k = 0; k < 3; k++){
                sum[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nProduct of Matrices\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
