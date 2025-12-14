#include "project_euler_002.h"
#include "unity.h"

void test_project_euler_002(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(4613732, project_euler_002(4000000), "project_euler_002");
}

// end
