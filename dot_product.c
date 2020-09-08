#include <stdio.h>
#include <math.h>
#include <omp.h>


int main () {

  float u[10], v[10], dp,dpp;
  int i, j, tid;

  dpp=0.0;
  for(i=0;i<10;i++){
      u[i]=1.0*(i+1);
      v[i]=1.0*(i+2);
  }
  
  printf("\n values of u and v:\n");
  for (i=0;i<10;i++){
      printf(" u[%d]= %.1f\t v[%d]= %.1f\n",i,u[i],i,v[i]);
  }
  
  
  #pragma omp parallel shared(u,v,dp,dpp) private (tid,i)
  {
      tid=omp_get_thread_num();

      #pragma omp for schedule(dynamic)
      for(i=0;i<10;i++){
          dpp+=u[i]*v[i];
          //printf("thread: %d\n", tid);
      }
          dp=dpp;
  }
  
  printf("\n Dot product is %f\n",dp);

 }
