#include <stdio.h>
#include <omp.h>

void merge(int a[], int i1, int j1, int i2, int j2)
{
	int temp[1000];
	int i, j, k;
	i = i1;
	j = i2;
	k = 0;

	while (i <= j1 && j <= j2){
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= j1)
		temp[k++] = a[i++];
	while (j <= j2)
		temp[k++] = a[j++];
	for (i = i1, j = 0; i <= j2; i++, j++)
		a[i] = temp[j];
}

void mergesort(int a[], int i, int j)
{
	int mid;
	if (i < j){
		
		mid = (i + j) / 2;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				mergesort(a, i, mid);
			}
			#pragma omp section
			{
				mergesort(a, mid + 1, j);
			}
		}
		merge(a, i, mid, mid + 1, j);
	}
}

int main()
{

	int arr[] = {4, 16, 1, 2, 13, 17, 20, 5, 2, 13, 8, 6, 11, 18, 13, 14, 12, 18, 19, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	double itime, ftime, timegap;
	int x, i;
	printf("Unsorted order\n");
	for (x = 0; x < n; x++){
		printf("%d ", arr[x]);
	}
	itime = omp_get_wtime();

	// Merge sort
	mergesort(arr, 0, n - 1);

	printf("\n\nSorted Order\n");
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}

	ftime = omp_get_wtime();
	timegap = ftime - itime;
	printf("\n\nTime taken is is %f", timegap);
}
