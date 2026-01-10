#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Finds the largest prime factor of an integer
 *
 * Special case: returns 0 if n < 2
 *
 * (v1 available in occisn/c-utils GitHub repository)
 */
static uint64_t largest_prime_factor_uint64(uint64_t n)
{
  if (n < 2) {
    return 0;
  }

  uint64_t largest = 0;

  // Remove all factors of 2
  while (n % 2 == 0) {
    largest = 2;
    n /= 2;
  }

  // Remove all factors of 3
  while (n % 3 == 0) {
    largest = 3;
    n /= 3;
  }

  // Now n is odd and not divisible by 3.
  // Test divisors of the form 6k-1 and 6k+1.
  uint64_t i = 5;
  while (i * i <= n) {

    // Check i = 6k - 1
    if (n % i == 0) {
      largest = i;
      n /= i;
    }
    // Check i+2 = 6k + 1
    else if (n % (i + 2) == 0) {
      largest = i + 2;
      n /= (i + 2);
    } else {
      i += 6;
    }
  }

  // If n is still > 1, it is prime
  if (n > 1)
    largest = n;

  return largest;
}

uint64_t project_euler_003(uint64_t n) // n = 600851475143
{
  uint64_t solution = largest_prime_factor_uint64(n);
  if (solution == 0) {
    perror("Problem with largest_prime_factor_uint64\n");
    return 0;
  }
  return solution;
}

// end
