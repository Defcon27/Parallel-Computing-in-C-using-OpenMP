#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{

    double x, dx, y, r1, r2, area = 0.0;
    int i;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();
    int iters = 10000000;
    dx = 1.0 / (double)iters;
    x = dx;

    #pragma omp parallel for schedule(dynamic) reduction(+: area) private(x, y, i, dx)
    for (i = 1; i < iters; i++)
    {
        dx = 1.0 / (double)iters;
        x = (double)i * dx;
        y = sqrt((double)1.0 - (pow(x, 2)));
        area += dx * y;
    }
    printf("\nPI value calculated is %f", area * 4.0);

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\n\nTime Taken = %f", timetaken);
}
