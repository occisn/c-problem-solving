#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>

/* Calculate largest prime factor of n (uint64_t)
 (v1 available in occisn/c-utils GitHub repository)*/
uint64_t largest_prime_factor__uint64(uint64_t n) {
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
        }
        else {
            i += 6;
        }
    }

    // If n is still > 1, it is prime
    if (n > 1)
        largest = n;

    return largest;
}


int project_euler_3 (void)
{
  // const uint64_t n = 13195;
  const uint64_t n = 600851475143;
  
  uint64_t solution = largest_prime_factor__uint64(n);

  printf("Solution: %" PRIu64 "\n", solution);
  return EXIT_SUCCESS;

}

int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  project_euler_3();

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
    
  return EXIT_SUCCESS;
}

// end
