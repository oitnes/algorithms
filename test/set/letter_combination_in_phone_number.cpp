#include "set/letter_combination_in_phone_number.hpp"

#include "../tools.hpp"

#include "gtest/gtest.h"

using namespace std;
using namespace letter_combination_in_phone_number;

TEST(LetterCombinationInPhoneNumber, basic_1) {
    string input("23");
    auto result = combine(input);
    vector<string> target{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    CHECK_EQUAL_ARRAYS(result, target)
}