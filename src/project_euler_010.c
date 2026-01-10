#include <inttypes.h> // for PRIu64
#include <math.h>     // for sqrtl
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Populate the Sieve of Eratosthenes up to n (exclusive)
 * and counts the number of primes.
 *
 * Array is created by the caller
 *
 * Return true/false if success/failure
 *
 * (v2 available in occisn/c-utils GitHub repository)
 */
static bool populate_sieve_eratosthenes_uint64(bool *is_prime, const uint64_t n)
{
  if (n < 1)
    return false;

  if (is_prime == NULL)
    return false;

  for (uint64_t i = 0; i < n; i++)
    is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;

  uint64_t limit = (uint64_t)sqrtl((long double)n);
  for (uint64_t p = 2; p <= limit; p++) {
    if (is_prime[p]) {
      for (uint64_t multiple = p * p; multiple < n; multiple += p) {
        is_prime[multiple] = false;
      }
    }
  }

  return true;
}


uint64_t project_euler_010(const uint64_t n) // n = 2M
{
  bool *is_prime = malloc(n * sizeof *is_prime);
  if (is_prime == NULL) {
    printf("Problem in malloc\n");
    return 0;
  }

  if (!populate_sieve_eratosthenes_uint64(is_prime, n)) {
    printf("Problem in populate_sieve_eratosthenes_uint64\n");
    free(is_prime);
    return 0;
  }
    
  uint64_t sum = 0;
  for (size_t i = 0; i < n; i++) {
    if (is_prime[i]) {
      sum += i;
    }
  }
  free(is_prime);
  return sum;
}

// end
