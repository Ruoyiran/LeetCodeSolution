//
// Created by ranpeng on 2020/4/16.
//
#include "common.h"

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:

Can you solve it without using extra space?
*/
class Solution {
public:
    ListNode *detectCycleV1(ListNode *head) {
        set<ListNode*> m;
        while (head != NULL) {
            if (m.find(head) != m.end()) {
                return head;
            }
            m.insert(head);
            head = head->next;
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        auto slow = head;
        auto fast = head;
        bool hasCycle = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) {
            return NULL;
        }
        // 相遇点到环入口点的距离 = 链表起始点到环入口点的距离
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {3,2,0,-4};
    auto head = buildList(nums);
    head->next->next->next->next = head->next;
    auto cycle = Solution().detectCycle(head);
    cout << cycle->val << endl;
    head->next->next->next->next = NULL;
    destroyList(head);
    return 0;
}