#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
  return (a < b) ? a : b;
}

static inline int max(int a, int b)
{
  return (a > b) ? a : b;
}

int project_euler_009(const int n) // n = 1000
{
   int res = 0;
  for (int c = n; c >= 3; c--) {
    // upper limit for b:
    //   (i) b < c
    //   (ii) b = 1000-c-a with a >= 1 thus b <= 1000-c-1
    // lower limit for b:
    //   (i) 1 <= a < b thus b > 1
    //   (ii) 1000-c = a+b with a < b thus 1000-c < 2b
    int bmax = min(c - 1, n - c - 1);
    int bmin = max(2, (n - c) / 2);
    for (int b = bmax; b >= bmin; b--) {
      int a = n - b - c;
      if (c * c == a * a + b * b) {
         res = a * b * c;
      }
    }
  }
  return res;
}

// end
