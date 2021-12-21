#pragma once

// https://leetcode.com/problems/subtree-of-another-tree/
namespace subtree_of_another_tree {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    namespace {

        bool checkStruct(TreeNode *root, TreeNode *target) noexcept {
            if ((root == nullptr) && (target == nullptr))
                return true;
            if ((root == nullptr) || (target == nullptr))
                return false;
            if (root->val != target->val)
                return false;

            return checkStruct(root->left, target->left) && checkStruct(root->right, target->right);
        }

        bool check(TreeNode *root, TreeNode *target) {
            return checkStruct(root, target) || check(root->left, target) || check(root->right, target);
        }

    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        return check(root, subRoot);
    }


}
