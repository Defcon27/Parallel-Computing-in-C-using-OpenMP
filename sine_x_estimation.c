#include <stdio.h>
#include <math.h>
#include <omp.h>

double fact(double num)
{
    int i, pro = 1;
    for (i = 1; i <= num; i++)
        pro = pro * i;
    return pro;
}

int main()
{
    double x = 60.0, rads, sum = 0;
    int i, j = 1;
    int iterations = 1000;
    double intm_value = 0;
    double sign = 1;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    rads = x * (3.1415 / 180);

    #pragma omp parallel for shared(sum)
    for (i = 1; i <= 15; i++)
    {
        intm_value = pow(rads, j) / fact(j);
        sign = 1;
        if (i % 2 == 0)
        {
            sign = -1;
        }
        sum += (sign * intm_value);
        j = j + 2;
    }

    printf("\nSine value approximation of 60 Degrees\n");
    printf("\nSin(%0.1f) = %f", x, sum);

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\n\nTime Taken = %f", timetaken);
    return 0;
}
