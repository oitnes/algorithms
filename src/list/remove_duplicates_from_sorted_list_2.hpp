#pragma once

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
namespace remove_duplicates_from_sorted_list_2 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *new_head = head;
        ListNode *current = head;
        ListNode *previous = head;

        while (current && current->next) {
            if (current->next->val != current->val) {
                if (current != new_head) {
                    previous = previous->next;
                }
                current = current->next;
            } else {
                ListNode *next = current->next;
                while (next && (next->val == current->val)) {
                    next = next->next;
                }
                if (current == new_head) {
                    new_head = next;
                    previous = next;
                    current = next;
                } else {
                    previous->next = next;
                    current = next;
                }
            }
        }
        return new_head;
    }

}