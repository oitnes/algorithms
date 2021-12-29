#include "multithreading/visitor/test.h"

#include <gtest/gtest.h>

using namespace std;
using namespace multithreading_visitor_test;

/***
 * Visits statistics of the institution.
 *
 * Key implementation points:
 * - statistics are collected for a specified time in seconds (program runtime)
 * - a new visitor comes in every rand (0-1000ms), the entry time is recorded
 * - visitor exits every rand (20-1000ms), exit time is fixed
 * - asynchronously, every 1000ms we record statistics of the current number of visitors
 *
 * On completion, output to the console:
 * - number of visitors every 1000ms
 * - average time spent by each in the institution
 * - the total number of visitors.
 ***/

TEST(Visitor, standart_1) {
    std::chrono::seconds statistic_time(20);
    std::cout << "start visitors meter test for " << std::to_string(statistic_time.count()) << " seconds." << std::endl;
    test(statistic_time);
}
