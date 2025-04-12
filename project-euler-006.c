#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

int project_euler_6 ()
{
  uint64_t res = 0;
  for (uint64_t i = 1; i <= 100; i++) {
    res = res + i;
  }
  res = res * res;
  for (uint64_t i = 1; i <= 100; i++) {
    res = res - i * i;
  }
  printf("Solution: %llu\n", res);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_6();

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
