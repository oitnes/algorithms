#pragma once

#define CHECK_EQUAL_ARRAYS(a1, a2) \
GTEST_ASSERT_EQ(a1.size(), a2.size()); \
for (int i = 0; i < a1.size(); i++) { GTEST_ASSERT_EQ(a1[i], a2[i]);}
