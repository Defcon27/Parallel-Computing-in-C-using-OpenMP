#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    float e = 1.0, fact = 1.0, x;
    int i = 0, steps = 10000;
    float itime, ftime, timetaken;

    itime = omp_get_wtime();

	#pragma omp parallel reduction(+: e)
    for (i = 1; i <= steps; i++)
    {
        fact *= i;
        x = 1.0 / fact;
        e += x;
    }

    printf("\ne value : %f\n", e);
    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\nTime Taken = %f", timetaken);
    return 0;
}
