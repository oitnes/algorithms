#include "list/remove_duplicates_from_sorted_list_2.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace remove_duplicates_from_sorted_list_2;

namespace remove_duplicates_from_sorted_list_2 {

    class ListCreator {
    private:
        vector<ListNode *> _for_remove;

    public:
        ListNode *root;

        ListCreator(const vector<int> &data) : root(nullptr) {
            for (int i = data.size() - 1; i >= 0; i--) {
                root = new ListNode(data[i], root);
                _for_remove.push_back(root);
            }
        }

        ~ListCreator() {
            for (auto el: _for_remove)
                delete el;
        }
    };

}

TEST(RemoveDuplicatesFromSortedList2, basic_1) {
    ListCreator input_data({1, 2, 3, 3, 4, 4, 5});
    auto result = deleteDuplicates(input_data.root);
    ListCreator target_data({1, 2, 5});
    CHECK_EQUAL_LISTS(result, target_data.root, [](ListNode *n) { return n->next; },
                      [](ListNode *n) { return n->val; });
}