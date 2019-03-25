#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int num_threads;
double *A, *B, *C;
int dimension;

void *matrix_mul(void *slice);

int main(int argc, char *argv[]) {
  int i, j;
  int *k;
  double start, end;
  pthread_t *threads;
  int num_threads = atoi(argv[1]);

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

  /* if num_threads == 1, the main process is the sole thread,
   * therefore we do not enter this loop.
   */
  for (i = 1; i < num_threads; i++) {
    k = malloc(sizeof(* k));
    *k = i;
    if (pthread_create (&threads[i], NULL, matrix_mul, k) != 0 ) {
      perror("Can't create thread");
      free(threads);
      exit(-1);
    }
  }

  /* the main program can also perform one portion of the tasks (one slice)
  */
  matrix_mul(0);

  // main thead waiting for other thread to complete
  for (i = 1; i < num_threads; i++)
    pthread_join (threads[i], NULL);

  free(A);
  free(B);
  free(C);
  return 0;
}

void *matrix_mul(void *slice) {
  int s = * (int *) slice;
  int start = (s * dimension)/num_threads; // note that this 'slicing' works fine
  int end = ((s + 1) * dimension)/num_threads; // even if SIZE is not divisible by num_thrd
  int i, j, k;

  for(i = start; i < end; i++)
    for(j = 0; j < dimension; j++)
      for(k = 0; k < dimension; k++)
        C[dimension*i+j] += A[dimension*i+k] * B[dimension*k+j];
  return 0;
}
