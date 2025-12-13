#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int project_euler_9(const int n) {
  int nbSolutions = 0;
  int res = 0;
  for (int c = n; c >= 3; c--) {
    // upper limit for b:
    //   (i) b < c
    //   (ii) b = 1000-c-a with a >= 1 thus b <= 1000-c-1
    // lower limit for b:
    //   (i) 1 <= a < b thus b > 1
    //   (ii) 1000-c = a+b with a < b thus 1000-c < 2b  
    int bmax = min(c-1, n-c-1);
    int bmin = max(2, (n-c)/2);
    for (int b = bmax; b >= bmin; b--) {
      int a = n-b-c;
      if (c*c == a*a + b*b) {
        nbSolutions++;
        res = a*b*c;
      }
    }
  }
  printf("Solution: %d (%d solution)\n", res, nbSolutions);
  return EXIT_SUCCESS;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {

  printf("\n");
  
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_9(1000);

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
