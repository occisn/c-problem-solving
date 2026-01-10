#include <stdlib.h>

int project_euler_006(const int n)
{
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = res + i;
  }
  res = res * res;
  for (int i = 1; i <= n; i++) {
    res = res - i * i;
  }
  return res;
}

// end
