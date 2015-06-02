#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char* argv[]){
	int n_threads = 8;
	int n = 10000000;
	double factor = 1.0;
	double sum = 0.0;
	int i = 0;
#   pragma omp parallel for num_threads(n_threads) \
    	reduction(+: sum) private(factor)
   	for (i = 0; i < n; i++) {
    	factor = (i % 2 == 0) ? 1.0 : -1.0; 
    	sum += factor/(2*i+1);
   }

   sum = 4.0*sum;
   printf("Estimated pi with %i threads and %i loops is : %f\n",n_threads, n,  sum);
}
