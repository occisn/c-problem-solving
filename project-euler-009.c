#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

/* To be compiled with:
gcc project-euler-009.c -Wall -Wextra -Werror -O3 -std=c2x -pedantic -o project-euler-009 */

/* Project Euler 9: Special Pythagorean Triplet
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2  
For example, 32 + 42 = 9 + 16 = 25 = 52.  
There exists exactly one Pythagorean triplet for which a + b + c = 1000.  
Find the product abc.
https://projecteuler.net/problem=9 */

uint64_t min(uint64_t a, uint64_t b) {
    return (a < b) ? a : b;
}

uint64_t max(uint64_t a, uint64_t b) {
    return (a > b) ? a : b;
}

int project_euler_9(void) {
  uint64_t n = 1000;
  uint64_t nbSolutions = 0;
  uint64_t res = 0;
  for (uint64_t c = n; c >= 3; c--) {
    // upper limit for b:
    //   (i) b < c
    //   (ii) b = 1000-c-a with a >= 1 thus b <= 1000-c-1
    // lower limit for b:
    //   (i) 1 <= a < b thus b > 1
    //   (ii) 1000-c = a+b with a < b thus 1000-c < 2b  
    uint64_t bmax = min(c-1, n-c-1);
    uint64_t bmin = max(2, (n-c)/2);
    for (uint64_t b = bmax; b >= bmin; b--) {
      uint64_t a = n-b-c;
      if (c*c == a*a + b*b) {
        nbSolutions++;
        res = a*b*c;
      }
    }
  }
  printf("Solution: %llu (%llu solution)\n", res, nbSolutions);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_9();

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
