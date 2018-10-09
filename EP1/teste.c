#include <stdio.h>
#include <time.h>

int main(void) {
  
  int t = time(NULL);
  int aux = 0;

  while(time(NULL) - t < 30) {
    if(time(NULL) != aux) {
      printf("Ola %ld\n", time(NULL) - t);
      aux = time(NULL);
    }
  }

  return 123;
}
