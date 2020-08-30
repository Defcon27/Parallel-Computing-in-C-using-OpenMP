#include <stdio.h>
#include <omp.h>

int main()
{
    int x[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    int i, j;
    int count = 0, num = 0;

    printf("\nInitial Declaration:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    #pragma omp parallel shared(count)
    {
        while (num < 2)
        {
            #pragma omp for
            for (i = 0; i < 5; i++){
                if (x[num][i] % 2 == 0){
                    count += 1;
                }
            }
            #pragma omp master
            {
                printf("\nMaster Thread:\nDone till %dth Array , Even nums count = %d", num, count);
                num += 1;
            }
		}   
    }
    
    return 0;
}


