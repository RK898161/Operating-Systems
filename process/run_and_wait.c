#include <stdio.h>
#include <unistd.h>

void child() {
  int i;
  for (i = 0; i < 10; i++) {
    printf("I am a child %d\n", i);
  }
  _exit(0);
}

void parent() {
  int i;
  int c;
  FILE *fp;
  fp = fopen("gutenberg-shakespeare.txt", "r");
  if (fp) {
    while ((c = getc(fp)) != EOF) {
      i = 0;
    }
  }
  fclose(fp);

  for (i = 0; i <10; i++) {
    printf("I am a parent %d\n", i);
  }
}

int main(int argc, char *argv[]){
  pid_t pid = fork();

  if (pid < 0) {
    printf("Fork failed\n");
  } 
  else if (pid == 0) {
    child();
  }
  else {
    parent();
  }
  return 0;
}
