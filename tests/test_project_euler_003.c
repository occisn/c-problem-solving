#include "project_euler_003.h"
#include "unity.h"

void test_project_euler_003(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(6857, project_euler_003(600851475143), "project_euler_003");
}

// end
