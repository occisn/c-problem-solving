#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int project_euler_2 (void) {
  int f1 = 1;
  int f2 = 2;
  int sum = 2;
  int tmp = 0;
  while (f2 <= 4000000) {
    tmp = f2;
    f2 = f1 + f2;
    f1 = tmp;
    if (f2 % 2 == 0) {
      sum += f2;
    }
  }
  printf("Solution: %i\n", sum);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_2();

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
