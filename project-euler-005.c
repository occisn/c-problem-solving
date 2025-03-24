#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

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

int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  uint64_t res = 1;
  for (uint64_t i = 1; i <= 20; i++) {
    res = lcm(res, i);
  }
  printf("Solution: %llu\n", res);
  return EXIT_SUCCESS;
}

// end
