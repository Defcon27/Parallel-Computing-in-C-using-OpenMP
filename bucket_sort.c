#include <stdio.h>
#include <omp.h>

int main()
{

	int arr[] = {4, 16, 1, 2, 13, 17, 20, 5, 2, 13, 8, 6, 11, 18, 13, 14, 12, 18, 19, 5,
				 9, 12, 14, 7, 3, 4, 15, 7, 9, 11, 2, 8, 15, 6, 3, 19, 3, 11, 16, 18, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int numbuc = 5;
	int bucket[4][10];
	double itime, ftime, timegap;
	int x;
	printf("Unsorted order\n");
	for (x = 0; x < n; x++)
	{
		printf("%d ", arr[x]);
	}
	itime = omp_get_wtime();

	int i, b, bi = -1, bj = -1, bk = -1, bl = -1;

	#pragma omp parallel for
	for (i = 0; i < n; i++)
	{
		b = arr[i] / numbuc;
		if (b == 0)
		{
			bucket[b][++bi] = arr[i];
		}
		else if (b == 1)
		{
			bucket[b][++bj] = arr[i];
		}
		else if (b == 2)
		{
			bucket[b][++bk] = arr[i];
		}
		if (b == 3)
		{
			bucket[b][++bl] = arr[i];
		}
	}

	int l, k, bui, temp;
	#pragma omp parallel
	{
		#pragma omp for
		for (bui = 0; bui < 4; bui++){
			
			for (l = 0; l < 9; l++){
				for (k = 0; k < 9 - l; k++){
					if (bucket[bui][k] > bucket[bui][k + 1]){
						temp = bucket[bui][k];
						bucket[bui][k] = bucket[bui][k + 1];
						bucket[bui][k + 1] = temp;
					}
				}
			}
		}
	}
	printf("\n\nSorted Order\n");
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%d ", bucket[i][j]);
		}
	}

	ftime = omp_get_wtime();
	timegap = ftime - itime;
	printf("\n\nTime taken is is %f", timegap);
}
