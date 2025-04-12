#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM
uint64_t lcm(uint64_t a, uint64_t b) {
    return (a * b) / gcd(a, b);  
}

int project_euler_5()
{
  uint64_t res = 1;
  for (uint64_t i = 1; i <= 20; i++) {
    res = lcm(res, i);
  }
  printf("Solution: %llu\n", res);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_5();

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
