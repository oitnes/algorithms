#pragma once

#include <gtest/gtest.h>

#include <future>

#define CHECK_EQUAL_PAIRS(p1, p2) \
GTEST_ASSERT_EQ(p1.first, p2.first); \
GTEST_ASSERT_EQ(p1.second, p2.second);

#define CHECK_EQUAL_LISTS(l1, l2, nextFn, getValFn) \
 auto el1 = l1; \
 auto el2 = l1; \
 while(el1 || el2){                                 \
    if (!el1 || !el2) {GTEST_ASSERT_TRUE(false); break;}\
    GTEST_ASSERT_EQ(getValFn(el1), getValFn(el2));                                      \
    el1 = nextFn(el1);                     \
    el2 = nextFn(el2);                     \
}                                           \

#define CHECK_EQUAL_ARRAYS(a1, a2) \
GTEST_ASSERT_EQ(a1.size(), a2.size()); \
for (int i = 0; i < a1.size(); i++) { GTEST_ASSERT_EQ(a1[i], a2[i]);}

#define CHECK_EQUAL_MAPS(m1, m2) \
GTEST_ASSERT_EQ(m1.size(), m2.size()); \
for (int i = 0; i < m1.size(); i++) {  \
GTEST_ASSERT_EQ(m1[i].size(), m2[i].size()); \
for (int j = 0; j < m1[i].size(); j++) { \
GTEST_ASSERT_EQ(m1[i][j], m2[i][j]);}} \

// https://antonlipov.blogspot.com/2015/08/how-to-timeout-tests-in-gtest.html
//#define TEST_TIMEOUT_BEGIN   std::promise<bool> promisedFinished; \
//auto futureResult = promisedFinished.get_future(); \
//std::thread([](std::promise<bool>& finished) {
//
//#define TEST_TIMEOUT_FAIL_END(X)  finished.set_value(true); \
//}, std::ref(promisedFinished)).detach(); \
//EXPECT_TRUE(futureResult.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);
//
//#define TEST_TIMEOUT_SUCCESS_END(X)  finished.set_value(true); \
//}, std::ref(promisedFinished)).detach(); \
//EXPECT_FALSE(futureResult.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);
