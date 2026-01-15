#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "project_euler_001.h"
#include "project_euler_002.h"
#include "project_euler_003.h"
#include "project_euler_004.h"
#include "project_euler_005.h"
#include "project_euler_006.h"
#include "project_euler_007.h"
#include "project_euler_008.h"
#include "project_euler_009.h"
#include "project_euler_010.h"

int main(void)
{
  printf("\n");

  struct timespec start, end;
  double duration;
  clock_gettime(CLOCK_MONOTONIC, &start);

  printf("Project Euler 001: %d\n", project_euler_001(1000));
  printf("Project Euler 002: %d\n", project_euler_002(4000000));
  printf("Project Euler 003: %" PRIu64 "\n", project_euler_003(600851475143));
  printf("Project Euler 004: %d\n", project_euler_004());
  printf("Project Euler 005: %d\n", project_euler_005(20));
  printf("Project Euler 006: %d\n", project_euler_006(100));
  printf("Project Euler 007: %d\n", project_euler_007(10001));
  printf("Project Euler 008: %" PRIu64 "\n", project_euler_008(13));
  printf("Project Euler 009: %d\n", project_euler_009(1000));
  printf("Project Euler 010: %" PRIu64 "\n", project_euler_010(2000000));

  clock_gettime(CLOCK_MONOTONIC, &end);
  duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Duration: %f seconds\n", duration);
  return EXIT_SUCCESS;
}

// end
