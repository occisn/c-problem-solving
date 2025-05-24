
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

/* To be compiled with:
gcc project-euler-006.c -Wall -Wextra -Werror -O3 -std=c2x -pedantic -o project-euler-006 */

/* Project Euler 6: Sum Square Difference
The sum of the squares of the first ten natural numbers is  
1^2 + 2^2 + ... + 10^2 = 385  
The square of the sum of the first ten natural numbers is  
(1 + 2 + ... + 10)^2 = 552 = 3025  
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.  
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.  
https://projecteuler.net/problem=6 */

int project_euler_6 () {
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

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
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
