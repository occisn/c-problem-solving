#include <inttypes.h> // for PRIu64
#include <math.h>     // for sqrtl
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Computes the Sieve of Eratosthenes up to n (exclusive)
 * and counts the number of primes.
 *
 * @param n         Upper limit (exclusive)
 * @return Pointer to dynamically allocated bool array where:
 *         is_prime[i] == true if i is prime, false otherwise.
 *         Returns NULL if n < 2 or memory allocation fails.
 *         Caller is responsible for freeing the array.
 *
 * (v1 available in occisn/c-utils GitHub repository)
 */
static bool *sieve_eratosthenes__uint64(uint64_t n)
{
  if (n < 2)
    return NULL;

  bool *is_prime = malloc(n * sizeof(bool));
  if (!is_prime)
    return NULL;

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

  return is_prime;
}

uint64_t project_euler_010(const uint64_t n) // n = 2M
{
  bool *is_prime = sieve_eratosthenes__uint64(n);

  if (is_prime == NULL) {
    printf("sieve_eratosthenes: memory allocation failed or n < 2\n");
    return EXIT_FAILURE;
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
