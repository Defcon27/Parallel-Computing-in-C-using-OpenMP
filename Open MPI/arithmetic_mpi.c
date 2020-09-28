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
    if (rank==0){
	int a=10;
	int b=20;
	int c=a+b;
	printf("\nSum from Rank_id-%d is %d\n",rank,c);
    }
    else if (rank==1){
	int a=15;
	int b=7;
	int c=a-b;
	printf("\nSubtraction from Rank_id-%d is %d\n",rank,c);
    }
    else if (rank==2){
	int x=12;
	int y=7;
	int z=x*y;
	printf("\nMultiplication from Rank_id-%d is %d\n",rank,z);
    }
    else if (rank==3){
	float x=16;
	float y=3;
	float z=x/y;
	printf("\nDivision from Rank_id-%d is %f\n",rank,z);
    }
    
    MPI_Finalize();
    return 0;
    
}
