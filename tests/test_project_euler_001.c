#include "project_euler_001.h"
#include "unity.h"

void test_project_euler_001(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(23, project_euler_001(10), "project_euler_001 (a)");
  TEST_ASSERT_EQUAL_INT_MESSAGE(233168, project_euler_001(1000), "project_euler_001 (b)");
}

// end
