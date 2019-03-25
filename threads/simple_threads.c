#include <stdio.h>
#include <pthread.h>

void *mythread(void *arg) {
  printf("%s\n", (char *) arg);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t p1, p2;
  int rc;
  printf("main: begin\n");
  rc = pthread_create(&p1, NULL, mythread, "A");
  rc = pthread_create(&p2, NULL, mythread, "B");

  // join waits for the threads to finish
  rc = pthread_join(p1, NULL);
  rc = pthread_join(p2, NULL); 
  printf("main: end\n");
  return 0;
}
