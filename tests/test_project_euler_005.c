#include "project_euler_005.h"
#include "unity.h"

void test_project_euler_005(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(2520, project_euler_005(10), "project_euler_005 (a)");
  TEST_ASSERT_EQUAL_INT_MESSAGE(232792560, project_euler_005(20), "project_euler_005 (b)");
}

// end
