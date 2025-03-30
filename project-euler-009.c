#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint64_t min(uint64_t a, uint64_t b) {
    return (a < b) ? a : b;
}

uint64_t max(uint64_t a, uint64_t b) {
    return (a > b) ? a : b;
}

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
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

// end
