#include <stdlib.h>

int project_euler_001(const int n) // n = 1000
{
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      sum += i;
    }
  }
  return sum;
}

// end
