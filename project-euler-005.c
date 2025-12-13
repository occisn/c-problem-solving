#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to calculate GCD
   a and b shall be positive
 (v1 available in occisn/c-utils GitHub repository) */
static int gcd__int(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

/* Function to calculate LCM
   a and b shall be positive
   Requires gcd__int()
 (v2 available in occisn/c-utils GitHub repository) */
static int lcm__int(int a, int b) {
  if (a == 0 || b == 0)
    return 0;
  return (int)((int64_t)a * b / gcd__int(a, b));
}

static int project_euler_5(const int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = lcm__int(res, i);
  }
  printf("Solution for %d: %d\n", n, res);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {

  printf("\n");

  project_euler_5(10);
  
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_5(20);

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
