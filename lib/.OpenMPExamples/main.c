#include <stdio.h> 
#include <omp.h> 

#ifdef _OPENMP 
	#include <omp.h> 
#else 
	#define omp_get_thread_num() 0 
#endif

int main (int argc, char *argv[]) { 
	int tid; 
	printf("Hello world from threads:\n"); 

	#pragma omp parallel private(tid) 
	{ 
		tid = omp_get_thread_num(); 
		printf("<%d>\n", tid); 
	} 

	printf("I am sequential now\n"); 

	int i;
	#pragma omp parallel for
	for(i=0; i <10-1; i++){
		printf("%d\n", i);

	}
	printf("I am sequential now\n"); 


	int N = 20;
	int chunk =5;
	float a[N], b[N], c[N]; 

	for (i=0; i < N; i++) 
		a[i] = b[i] = i * 1.0; 

	#pragma omp parallel shared(a,b,c,chunk) private(i)
	{
		#pragma omp for schedule(dynamic,chunk) nowait
		for (i=0; i < N; i++){
			
			tid = omp_get_thread_num(); 
			printf("<%d>\n", tid); 

			c[i] = a[i] + b[i]; 
			printf("c[%d] = a[%d] + b[%d] = %0.1f = %0.1f + %0.1f \n", i, i, i, c[i], a[i], b[i]); 
		}
	}


	return 0; 
} 
