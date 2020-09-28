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
	printf("\nRank_id-%d sending msg=50 to process 2\n",rank);
	int a=50;
	int *p = &a;
	MPI_Send(p,1,MPI_INT,1,0,MPI_COMM_WORLD);
    }
    else if (rank==1){
	int b;
	int *p2=&b;
	MPI_Recv(p2,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	printf("\nRank_id-%d recieved msg:%d from process 1\n",rank,*p2);
    }
    
    MPI_Finalize();
    return 0;
    
}
