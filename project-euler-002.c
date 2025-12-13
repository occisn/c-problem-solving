#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static int project_euler_2 (const int n) {
  int f1 = 1;
  int f2 = 2;
  int sum = 2;
  while (f2 <= n) {
    int tmp = f2;
    f2 = f1 + f2;
    f1 = tmp;
    if (f2 % 2 == 0) {
      sum += f2;
    }
  }
  printf("Solution: %d\n", sum);
  return EXIT_SUCCESS;
}

int main(void) {

  printf("\n");
  
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_2(4000000);

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
