#include "tree/subtree_of_another_tree.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace subtree_of_another_tree;

TEST(SubtreeOfAnotherTree, basic_1) {
    TreeNode *root = new TreeNode(3, new TreeNode(4),new TreeNode(5));
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *sub_root = new TreeNode(4, new TreeNode(1),new TreeNode(2));

    GTEST_ASSERT_TRUE(isSubtree(root, sub_root));

    delete sub_root->left;
    delete sub_root->right;
    delete sub_root;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}