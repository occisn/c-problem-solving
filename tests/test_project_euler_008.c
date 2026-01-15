#include "project_euler_008.h"
#include "unity.h"

void test_project_euler_008(void)
{
  TEST_ASSERT_EQUAL_UINT64_MESSAGE(5832, project_euler_008(4), "project_euler_008 (a)");
  TEST_ASSERT_EQUAL_UINT64_MESSAGE(23514624000, project_euler_008(13), "project_euler_008 (b)");
}

// end
