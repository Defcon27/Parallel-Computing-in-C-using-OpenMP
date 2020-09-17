#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int i,n=9;
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target=6,index=-1;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("Array Declaration:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nTarget : %d",target);

    
	#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        if (arr[i]==target){
			index=i;
		}
    }

    printf("\n\nIndex of target in arr : %d\n",index);
  
    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
