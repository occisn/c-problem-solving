#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate GCD
   a and b shall be positive
 (v1 available in occisn/c-utils GitHub repository) */
static int gcd_int(int a, int b)
{
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

/* Function to calculate LCM
   a and b shall be positive
   Requires gcd_int()
 (v2 available in occisn/c-utils GitHub repository) */
static int lcm_int(int a, int b)
{
  if (a == 0 || b == 0)
    return 0;
  return (int)((int64_t)a * b / gcd_int(a, b));
}

int project_euler_005(const int n) // n = 20
{
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = lcm_int(res, i);
  }
  return res;
}

// end
