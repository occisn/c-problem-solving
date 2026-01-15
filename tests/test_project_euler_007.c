#include "project_euler_007.h"
#include "unity.h"

void test_project_euler_007(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(13, project_euler_007(6), "project_euler_007 (a)");
  TEST_ASSERT_EQUAL_INT_MESSAGE(104743, project_euler_007(10001), "project_euler_007 (b)");
}

// end
