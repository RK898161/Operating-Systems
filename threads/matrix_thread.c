#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int num_threads;
double *A, *B, *C;
int dimension;

void matrix_mul(int slice);

int main(int argc, char *argv[]) {
  int i, j, k;
  double start, end;
  pthread_t *threads;
  int num_threads = atoi(argv[1);

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

  thread = (pthread_t *) malloc(num_threads * sizeof(pthread_t));

  /* if num_threads == 1, the main process is the sole thread,
   * therefore we do not enter this loop.
   */
  for (i = 1; i < num_threads; i++) {
    if (pthread_create (&thread[i], NULL, matrix_mul, (int *)i) != 0 ) {
      perror("Can't create thread");
      free(thread);
      exit(-1);
    }
  }

  /* the main program can also perform one portion of the tasks (one slice)
  */
  matrix_mul(0);

  // main thead waiting for other thread to complete
  for (i = 1; i < num_threads; i++)
    pthread_join (thread[i], NULL);

  free(A);
  free(B);
  free(C);
  return 0;
}

void matrix_mul(int *slice) {
  int start = ((int)(slice) * dimension)/num_threads; // note that this 'slicing' works fine
  int end = (((int)(slice) + 1) * SIZE)/num_threads; // even if SIZE is not divisible by num_thrd
  int i, j, k;

  for(i = from; i < to; i++)
    for(j = 0; j < dimension; j++)
      for(k = 0; k < dimension; k++)
        C[dimension*i+j] += A[dimension*i+k] * B[dimension*k+j];
}
