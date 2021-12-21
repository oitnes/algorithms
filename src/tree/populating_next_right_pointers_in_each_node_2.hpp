#pragma once

#include <vector>

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
namespace populating_next_right_pointers_in_each_node_two {

    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

        Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

        Node(int _val, Node *_left, Node *_right, Node *_next)
                : val(_val), left(_left), right(_right), next(_next) {}
    };

    namespace {
        void deep(Node *root, std::vector<Node *> &nodes_right, int layer) {
            if (!root)
                return;
            if (nodes_right.size() > layer) {
                root->next = nodes_right[layer];
                nodes_right[layer] = root;
            } else {
                root->next = nullptr;
                nodes_right.push_back(root);
            }
            deep(root->right, nodes_right, layer + 1);
            deep(root->left, nodes_right, layer + 1);
        }
    }

    Node *connect(Node *root) {
        std::vector<Node *> nodes_right;
        deep(root, nodes_right, 0);
        return root;
    }

}