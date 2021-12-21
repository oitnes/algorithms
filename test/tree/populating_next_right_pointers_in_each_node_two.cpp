#include "tree/populating_next_right_pointers_in_each_node_2.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace populating_next_right_pointers_in_each_node_two;

TEST(PopulatingNextRightPointersInEachNodeTwo, basic_1) {
    Node *root = new Node(1);
    root->left = new Node(2, new Node(4), new Node(5), nullptr);
    root->right = new Node(3, nullptr, new Node(7), nullptr);

    auto result = connect(root);

    GTEST_ASSERT_EQ(result->left->val, 2);
    GTEST_ASSERT_EQ(result->left->next->val, 3);
    GTEST_ASSERT_EQ(result->left->left->next->val, 5);
    GTEST_ASSERT_EQ(result->left->right->next->val, 7);

    delete result->right->right;
    delete result->right;
    delete result->left->right;
    delete result->left->left;
    delete result->left;
    delete result;
}