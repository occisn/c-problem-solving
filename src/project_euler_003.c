#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Finds the largest prime factor of a given unsigned 64-bit integer.
 *
 * This function uses an optimized trial division algorithm:
 * 1. First removes all factors of 2 (the only even prime)
 * 2. Then removes all factors of 3
 * 3. Finally checks only numbers of the form 6k±1 (where k ≥ 1), since all
 *    primes greater than 3 can be expressed in this form
 *
 * The algorithm repeatedly divides n by each prime factor found, effectively
 * computing the complete prime factorization while only tracking the largest.
 *
 * @param n The number to factorize (must be a positive integer)
 *
 * @return The largest prime factor of n.
 * Special case: returns 0 if n is 0 or 1 (no prime factors exist)
 *
 * @example
 *   largest_prime_factor__uint64(28)      returns 7   (28 = 2² × 7)
 *
 * (v1 available in occisn/c-utils GitHub repository)
 */
static uint64_t largest_prime_factor__uint64(uint64_t n)
{
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
  while (i <= n / i) { // to avoid overflow

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

int64_t project_euler_003(const uint64_t n) // n = 600851475143
{
  uint64_t solution = largest_prime_factor__uint64(n);
  return solution;
}

// end
