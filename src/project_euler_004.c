#include <stdlib.h>
#include <assert.h>

/**
 * Reverse the digits of a non-negative integer.
 *
 * (v1 available in occisn/c-utils GitHub repository, 2025-12-19)
 */
static int reverse_number_int(int n)
{
  assert(n >= 0);
  int reversed = 0;
  while (n > 0) {
    reversed = reversed * 10 + (n % 10);
    n /= 10;
  }
  return reversed;
}


int project_euler_004(void)
{
  int max_palindrome = 0;
  for (int i = 999; i >= 100; --i) {
    for (int j = i; j >= 100; --j) {
      int product = i * j;
      if (product <= max_palindrome) {
        break;
      }
      if (product == reverse_number_int(product)) {
        max_palindrome = product;
      }
    }
  }
  return max_palindrome;
}

// end
