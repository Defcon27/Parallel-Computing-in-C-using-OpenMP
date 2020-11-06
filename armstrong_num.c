#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int max_thrds = omp_get_max_threads();
    omp_set_num_threads(max_thrds);
    int i, j, num, flag,rem,res;

	#pragma omp parallel for schedule(dynamic) private(num,res,rem)
	for (i = 2; i < 1000; i++)
	{
		rem=0,res=0;
		num=i;
		while (num != 0) {
			rem = num % 10;
			res += (rem * rem * rem);
			num /= 10;
		}
		if (res == i){
			int tid = omp_get_thread_num();
			printf("%d is Armstrong number from thread-%d\n",i,tid);
		}			   
	}
}
