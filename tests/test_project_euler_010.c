#include "project_euler_010.h"
#include "unity.h"

void test_project_euler_010(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(17, project_euler_010(10), "project_euler_010 (a)");
  TEST_ASSERT_EQUAL_INT_MESSAGE(142913828922, project_euler_010(2000000), "project_euler_010 (b)");
}

// end
