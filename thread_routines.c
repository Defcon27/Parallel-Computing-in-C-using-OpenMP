#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int max_thrds = omp_get_max_threads();
    int tid;
    omp_set_num_threads(max_thrds);
    int x=10;

	#pragma omp parallel private(tid, x)
    {
        tid = omp_get_thread_num();
        if tid ==0{
			int area_tri = (1/2)*x*x;
			printf("Area of triangle: %d",area_tri);
		}
		else if tid==1{
			float area_cir = (3.14)*x*x;
			printf("Area of triangle: %d",area_cir);
		}
	}
	
}
			
    
}
