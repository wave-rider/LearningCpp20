#include "pch.h"
#include "Solution.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
  int sizes[] = { 1,2,3,2,4,1,3 };
  Solution solution;
  auto result = solution.solve(sizes);
  EXPECT_TRUE(result, 7);
}