#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int n = 120;
	float float_arr[n];
	int bins = 10;
	int hist[bins + 1];
	double itime, ftime, timetaken;
	int i, j, count;

	itime = omp_get_wtime();

	// Generating random float data
	printf("Random Float data\n");
	srand(0);
	#pragma omp parallel for private(i)
	for (i = 0; i < n; i++)
	{
		float random = ((float)rand() / (float)(RAND_MAX));
		float_arr[i] = random;
		printf("%f  ", random);
	}

	#pragma omp parallel for
	for (i = 0; i <= bins; i++)
		hist[i] = 0;


	//Dividing float data into bins
	
	#pragma omp parallel for schedule(dynamic) private(i, j)
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= bins; j++)
		{
			float bin_max = (float)j / (float)bins;
			if (float_arr[i] <= bin_max)
			{
				hist[j]++;
				break;
			}
		}
	}

	// Plotting histogram
	printf("\n\nHistogram of Float data for Bins=%d\n", bins);
	for (i = 1; i <= bins; i++)
	{
		count = hist[i];
		printf("0.%d |", i - 1);
		for (j = 0; j < count; j++)
		{
			printf("%c", (char)254u);
		}
		printf("\n");
	}

	ftime = omp_get_wtime();
	timetaken = ftime - itime;
	printf("\nTime Taken = %f", timetaken);
	return 0;
}
