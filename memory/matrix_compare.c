#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

struct timeval tv; 

double timestamp();
double* matrix_mul_v1(double *A, double *B, int dimension);
double* matrix_mul_v2(double *A, double *B, int dimension);
int validate(double *C1, double *C2, int dimension); 

int main(int argc, char *argv[]) {
  int i, j, k;
  double *A, *B, *C1, *C2, start, end;
  int dimension = atoi(argv[1]); 
    
  A = (double*)malloc(dimension*dimension*sizeof(double));
  B = (double*)malloc(dimension*dimension*sizeof(double));
  
  srand(42);
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++) {   
      A[dimension*i+j] = (rand()/(RAND_MAX + 1.0));
      B[dimension*i+j] = (rand()/(RAND_MAX + 1.0));
    }   

  C1 = (double *) matrix_mul_v1(A, B, dimension);
  C2 = (double *) matrix_mul_v2(A, B, dimension);
  validate(C1, C2, dimension);
  free(A);
  free(B);
  free(C1);
  free(C2);
    
  return 0;
}

double* matrix_mul_v1(double *A, double *B, int dimension) {
  int i, j, k;
  double start, end;
  double *C = (double*)malloc(dimension*dimension*sizeof(double));
  
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++)          
      C[dimension*i+j] = 0.0;
  start = timestamp();
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++)
      for(k = 0; k < dimension; k++)
        C[dimension*i+j] += A[dimension*i+k] * B[dimension*k+j];
  end = timestamp();
  printf("v1 secs:%f\n", end-start);   
  return C;
}

double* matrix_mul_v2(double *A, double *B, int dimension) {
  int i, j, k;
  double start, end;
  double *C = (double*)malloc(dimension*dimension*sizeof(double));
  
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++)          
      C[dimension*i+j] = 0.0;
  start = timestamp();
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++)
      for(k = 0; k < dimension; k++)
        C[dimension*i+k] += A[dimension*i+j] * B[dimension*j+k];
  end = timestamp();
  printf("v2 secs:%f\n", end-start);
  return C;
}

int validate(double *C1, double *C2, int dimension) {
  int i, j;  
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++)
      if (C1[dimension*i+j] != C2[dimension*i+j]) {
        printf("Mismatch!\n");                   
        return 0;  
      }   
  return 1;
}

double timestamp() {
  double t;
  gettimeofday(&tv, NULL);
  t = tv.tv_sec + (tv.tv_usec/1000000.0);
  return t;
}