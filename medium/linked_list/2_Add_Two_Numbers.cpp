//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto *dummyHead = new ListNode(0);
        auto *head = dummyHead;
        while(l1 != NULL || l2 != NULL) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int s = val1 + val2 + carry;
            int v = s % 10;
            carry = s / 10;
            head->next = new ListNode(v);
            head = head->next;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            head->next = new ListNode(carry);
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {
    vector<int> nums1 = {1};
    vector<int> nums2 = {9,9,9};
    ListNode *l1 = buildList(nums1);
    ListNode *l2 = buildList(nums2);
    Solution solution;
    auto l3 = solution.addTwoNumbers(l1, l2);
    printList(l1);
    printList(l2);
    printList(l3);
    destroyList(l1);
    destroyList(l2);
    destroyList(l3);
    return 0;
}