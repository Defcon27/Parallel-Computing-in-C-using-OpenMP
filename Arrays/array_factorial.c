#include <stdio.h>
#include <math.h>
#include <omp.h>


int main()
{
    int n = 12;
    int arr[10] = {2,4,5,6,1,2,3,8,7,9};
    int num,fact=1;
    int i, j;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nArray of number:\n");
    for(i=0;i<10;i++){
        printf("%d ",arr[i]);
    }

    #pragma omp parallel for
    for(i=0;i<10;i++)
    {
        num = arr[i];
        fact=1;
        for(j=1;j<=num;j++)
        {
            fact*=j;
        }
        printf("\nFactorial of %d is %d from thread-%d",num,fact,omp_get_thread_num());
    }
      

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\n\nTime Taken = %f", timetaken);
    return 0;
}
