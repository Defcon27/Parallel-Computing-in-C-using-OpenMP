#include <stdio.h>

int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    int target = 4;
    int i, ind;

    printf("\nInitial Declaration:\n");
    for (i = 0; i < 5; i++){
        printf("%d ", x[i]);
    }

    #pragma omp parallel shared(x)
    {
        #pragma omp single
        printf("\nStarting search...\n");

        #pragma omp for
        for (i = 0; i < 5; i++){
            if (x[i] == target){
                ind = i;
            }
        }

        #pragma omp single
        printf("\nTarget at Index %d", ind);
    }
    
    return 0;
}
