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
		printf("Rank_id-%d sending msg to process 2",rank);
		int a=30;
		int *p = &a;
		MPI_Send(p,1,MPI_INIT,1,0,0,MPI_COMM_WORLD);
	}
	else if (rank==1){
		int b;
		int *p2=&b;
		MPI_Recv(p2,1,MPI_INIT,2,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Rank_id-%d recieved msg:%d from process 1",rank,p2);
	}
    
    MPI_Finalize();
    return 0;
    
}
