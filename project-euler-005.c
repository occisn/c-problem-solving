#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

/* To be compiled with:
gcc project-euler-005.c -Wall -Wextra -Werror -O3 -std=c2x -pedantic -o project-euler-005 */

/* Project Euler 5: Smallest Multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
https://projecteuler.net/problem=5 */

/* Function to calculate GCD */
uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to calculate LCM */
uint64_t lcm(uint64_t a, uint64_t b) {
    return (a * b) / gcd(a, b);  
}

int project_euler_5() {
  uint64_t res = 1;
  for (uint64_t i = 1; i <= 20; i++) {
    res = lcm(res, i);
  }
  printf("Solution: %llu\n", res);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
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
