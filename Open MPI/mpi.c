#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int size=4;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("\nHello World from rankID %d  Total-%d\n",rank,size);
    MPI_Finalize();
    
    return 0;
    
}
