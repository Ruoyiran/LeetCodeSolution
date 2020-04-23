//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

/*
 Given a linked list, determine if it has a cycle in it.
 To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the
 linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {3, 2, 0, -4};
    ListNode *head = buildList(nums);
    Solution solution;
    cout << solution.hasCycle(head) << endl;
    head->next->next->next->next = head->next;
    cout << solution.hasCycle(head) << endl;
    head->next->next->next->next = NULL;
    destroyList(head);
    return 0;
}