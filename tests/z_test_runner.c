#include "unity.h"

void test_project_euler_001(void);
void test_project_euler_002(void);
void test_project_euler_003(void);
void test_project_euler_005(void);
void test_project_euler_006(void);
void test_project_euler_007(void);
void test_project_euler_008(void);
void test_project_euler_009(void);
void test_project_euler_010(void);

void setUp(void) {
  //
}

void tearDown(void) {
  //
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_project_euler_001);
  RUN_TEST(test_project_euler_002);
  RUN_TEST(test_project_euler_003);
  RUN_TEST(test_project_euler_005);
  RUN_TEST(test_project_euler_006);
  RUN_TEST(test_project_euler_007);
  RUN_TEST(test_project_euler_008);
  RUN_TEST(test_project_euler_009);
  RUN_TEST(test_project_euler_010);

  return UNITY_END();
}

// end
