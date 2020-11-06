#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    int integer = 27;
    int tid;
    int i, j, n;
    double itime, ftime, timetaken;
    itime = omp_get_wtime();

    printf("\nNumber to be converted:%d\n", integer);

    #pragma omp parallel private(i, j, tid)
    {
        tid = omp_get_thread_num();
        //Decimal to Binary
        if (tid == 0){
            int bin[100];
            int num = integer;
            for (i = 0; num > 0; i++){
                bin[i] = num % 2;
                num = num / 2;
            }
            printf("\nBinary Convertion: ");
            for (j = 0; j < i; j++){
                printf("%d", bin[j]);
            }
        }

        //Decimal to Octal
        if (tid == 1){
            int oct[100];
            int num = integer;
            for (i = 0; num > 0; i++){
                oct[i] = num % 8;
                num = num / 8;
            }
            printf("\nOctal Convertion: ");
            for (j = 0; j < i; j++){
                printf("%d", oct[j]);
            }
        }

        //Decimal to Hexadecimal
        if (tid == 2){
            char hex[100];
            int rem, num = integer;
            i = 0;
            while (num != 0){
                rem = num % 16;
                if (rem < 10)
                    hex[i++] = 48 + rem;
                else
                    hex[i++] = 55 + rem;
                num /= 16;
            }
            printf("\nHex Convertion: ");
            for (j = 0; j < i; j++){
                printf("%c", hex[j]);
            }
        }
    }

    ftime = omp_get_wtime();
    timetaken = ftime - itime;
    printf("\n\nTime Taken = %f", timetaken);
    return 0;
}

