#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int project_euler_1(const int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      sum += i;
    }
  }
  printf("Solution for n = %d: %d\n", n, sum);
  return EXIT_SUCCESS;
}

int main(void) {

  printf("\n");
  project_euler_1(10);
  
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_1(1000);

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
