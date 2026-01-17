#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Populate the Sieve of Eratosthenes up to n (exclusive)
 * and counts the number of primes.
 *
 * Array of size n is created by the caller
 *
 * Return true/false if success/failure
 *
 * (v2 available in occisn/c-utils GitHub repository)
 */
static bool populate_sieve_eratosthenes_uint64(bool *is_prime, uint64_t n)
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

/**
 * Returns n-th prime via out-parameter.
 *
 * @return true on success, false on failure
 *
 * (v2 available in occisn/c-utils GitHub repository)
 */
static bool nth_prime_uint64(uint64_t n, uint64_t *result)
{
  if (n < 1 || result == NULL) {
    return false;
  }

  // Initial upper bound estimate for n-th prime
  double estimate = (n >= 6) ? n * (log(n) + log(log(n))) : 15;
  uint64_t limit = (uint64_t)estimate + 1;

  bool *is_prime = malloc(limit * sizeof *is_prime);
  if (is_prime == NULL) {
    fprintf(stderr, "Problem in malloc.\n");
    return false;
  }

  // populate sieve
  if (!populate_sieve_eratosthenes_uint64(is_prime, limit)) {
    fprintf(stderr, "Problem in populate_sieve_eratosthenes_uint64.\n");
    goto failure;
  }

  if (n == 1) {
    *result = 2;
  } else {
    size_t count = 0;
    size_t i = 0;
    for (i = 0; i < limit; i++) {
      if (is_prime[i])
        count++;
      if (count == n)
        break;
    }

    if (count < n) {
      free(is_prime);
      return false;
    }

    *result = i;
  }

failure:
  free(is_prime);
  return true;
}

static bool SHOW_nth_prime_uint64(void)
{
  const uint64_t n = 1000;
  uint64_t nth_prime;
  if (!nth_prime_uint64(n, &nth_prime)) {
    fprintf(stderr, "Problem with nth_prime_uint64\n");
    return false;
  }
  printf("%" PRIu64 "-th prime is %" PRIu64 "\n", n, nth_prime);
  return true;
}

int project_euler_007(int n)
{
  uint64_t nth_prime;
  if (!nth_prime_uint64(n, &nth_prime)) {
    fprintf(stderr, "Problem with nth_prime_uint64\n");
    return 0;
  }
  return nth_prime;
}

// end
