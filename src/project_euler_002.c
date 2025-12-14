#include <stdio.h>
#include <stdlib.h>

int project_euler_002(const int n) // n = 4 M
{
  int f1 = 1;
  int f2 = 2;
  int sum = 2;
  while (f2 <= n) {
    int tmp = f2;
    f2 = f1 + f2;
    f1 = tmp;
    if (f2 % 2 == 0) {
      sum += f2;
    }
  }
  return sum;
}

// end
