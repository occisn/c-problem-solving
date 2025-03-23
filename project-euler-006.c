#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, [[maybe_unused]] char* argv[argc+1])
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

// end
