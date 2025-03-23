#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  uint64_t sum = 0;
  for (uint64_t i = 1; i < 1000; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
        sum += i;
      }
  }
  printf("Solution: %llu\n", sum);
  return EXIT_SUCCESS;
}

// end
