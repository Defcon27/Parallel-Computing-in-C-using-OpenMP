#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int size;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("Hello World from rankID %d  Total-%d",rank,size);
    
    if (rank==0){
		int a=10;
		int b=20;
		int c=a+b;
		printf("Sum from Rank_id:%d is %d",c,rank);
	}
	else if (rank==1){
		int x=15;
		int y=7;
		int z=x*y;
		printf("Product from Rank_id:%d is %d",z,rank);
	}
    
    MPI_Finalize();
    return 0;
    
}
