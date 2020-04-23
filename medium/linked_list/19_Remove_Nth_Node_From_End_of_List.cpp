//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
class Solution {
public:
    ListNode* removeNthFromEndV1(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        int len = getListLength(head);
        if (len == n) {
            head = head->next;
            return head;
        }
        head = reverseList(head);
        if (n == 1) {
            head = head->next;
            head = reverseList(head);
            return head;
        }

        ListNode* headCopy = head;
        for (int i = 0; i < n-2; ++i) {
            head = head->next;
        }
        auto tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return reverseList(headCopy);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n && fast != NULL; ++i) {
            fast = fast->next;
        }
        if (fast == NULL) {
            auto tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return head;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = buildList(nums);
    printList(head);
    auto newHead = solution.removeNthFromEnd(head, 1);
    printList(newHead);
    destroyList(head);
    return 0;
}