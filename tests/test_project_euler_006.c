#include "project_euler_006.h"
#include "unity.h"

void test_project_euler_006(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(2640, project_euler_006(10), "project_euler_006 (a)");
  TEST_ASSERT_EQUAL_INT_MESSAGE(25164150, project_euler_006(100), "project_euler_006 (b)");
}

// end
