#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int num_threads;
double *A, *B, *C;
int dimension;

void *matrix_mul(void *slice);
void print_matrix(double *matrix, int dimension);

int main(int argc, char *argv[]) {
  int i, j;
  int *k;
  pthread_t *threads;
  num_threads = atoi(argv[1]);
  dimension = atoi(argv[2]);

  A = (double*)malloc(dimension*dimension*sizeof(double));
  B = (double*)malloc(dimension*dimension*sizeof(double));
  C = (double*)malloc(dimension*dimension*sizeof(double));

  srand(42);
  for(i = 0; i < dimension; i++)
    for(j = 0; j < dimension; j++) {
      A[dimension*i+j] = (rand()/(RAND_MAX + 1.0));
      B[dimension*i+j] = (rand()/(RAND_MAX + 1.0));
      C[dimension*i+j] = 0.0;
    }

  threads= (pthread_t *) malloc(num_threads * sizeof(pthread_t));

  for (i = 0; i < num_threads; i++) {
    k = malloc(sizeof(int));
    *k = i;
    if (pthread_create (&threads[i], NULL, matrix_mul, k) != 0 ) {
      perror("Can't create thread");
      free(threads);
      exit(-1);
    }
  }

  // main thead waiting for other thread to complete
  for (i = 0; i < num_threads; i++)
    pthread_join (threads[i], NULL);

  if (dimension < 10) {
    printf("A ======================\n");
    print_matrix(A, dimension);
    printf("B ======================\n");
    print_matrix(B, dimension);
    printf("C ======================\n");    
    print_matrix(C, dimension);
  }
  free(A);
  free(B);
  free(C);
  return 0;
}

void *matrix_mul(void *slice) {
  int s = *((int *) slice);
  int start = (s * dimension)/num_threads; // note that this 'slicing' works fine
  int end = ((s + 1) * dimension)/num_threads; // even if SIZE is not divisible by num_threads
  printf("Thread %d with starting row %d and ending row %d\n", s, start, end);
  int i, j, k;

  for(i = start; i < end; i++)
    for(j = 0; j < dimension; j++)
      for(k = 0; k < dimension; k++)
        C[dimension*i+j] += A[dimension*i+k] * B[dimension*k+j];
  return 0;
}

void print_matrix(double *matrix, int dimension) {
  int i, j;
  for (i = 0; i < dimension; ++i) {
    for (j = 0; j < dimension - 1; ++j) {
      printf("%lf, ", matrix[dimension * i + j]);
    }
    printf("%lf", matrix[dimension * i + j]);
    putchar('\n');
  }
}
