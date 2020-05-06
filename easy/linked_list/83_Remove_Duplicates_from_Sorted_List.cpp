//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        auto curr = head, next = head->next;
        while (curr != NULL && next != NULL) {
            if (curr->val == next->val) {
                auto tmp = next;
                curr->next = next->next;
                next = next->next;
                delete tmp;
            } else {
                curr = curr->next;
                next = next->next;
            }
        }
        return head;
    }
};

int main() {
    vector<int> nums = {1,2,2,2,3,3,4,5, 5,5};
    auto head = buildList(nums);
    auto newHead = Solution().deleteDuplicates(head);
    printList(newHead);
    destroyList(head);
    return 0;
}