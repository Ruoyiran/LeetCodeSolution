//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

// 将已排好序的两个链表连接到一起，返回连接的链表。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* dummyNode = new ListNode(0);
        ListNode* pHead = dummyNode;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                pHead->next = new ListNode(l1->val);
                pHead = pHead->next;
                l1 = l1->next;
            } else if (l1->val > l2->val) {
                pHead->next = new ListNode(l2->val);
                pHead = pHead->next;
                l2 = l2->next;
            } else {
                pHead->next = new ListNode(l1->val);
                pHead->next->next = new ListNode(l2->val);
                pHead = pHead->next->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (l1 != NULL) {
            pHead->next = l1;
        }
        if (l2 != NULL) {
            pHead->next = l2;
        }
        pHead = dummyNode->next;
        delete dummyNode;
        return pHead;
    }
};

int main() {
    ListNode *l1 = buildList({1, 2, 4, 9, 100});
    ListNode *l2 = buildList({1, 3, 4, 8, 91});
    Solution solution;
    ListNode* l3 = solution.mergeTwoLists(l1, l2);
    printList(l1);
    printList(l2);
    printList(l3);

    destroyList(l1);
    destroyList(l2);
    destroyList(l3);
}
