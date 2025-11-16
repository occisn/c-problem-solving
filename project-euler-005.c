#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Function to calculate GCD
 (v1 available in occisn/c-utils GitHub repository) */
int gcd__int(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to calculate LCM
   Requires gcd__int()
 (v1 available in occisn/c-utils GitHub repository) */
int lcm__int(int a, int b) {
    return (a * b) / gcd__int(a, b);  
}

int project_euler_5(void) {
  const int n = 20;
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = lcm__int(res, i);
  }
  printf("Solution: %i\n", res);
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
