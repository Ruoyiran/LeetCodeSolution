//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"

/*
Write a program to find the node at which the intersection of two singly linked lists begins.



For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        if (lenA > lenB) {
            for (int i = 0; i < lenA-lenB; ++i) {
                headA = headA->next;
            }
        } else if (lenB > lenA) {
            for (int i = 0; i < lenB-lenA; ++i) {
                headB = headB->next;
            }
        }
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main() {
    vector<int> numsA = {4,1};
    vector<int> numsB = {5,0,1};
    vector<int> numsC = {8,4,5};
    ListNode *headA = buildList(numsA);
    ListNode *headB = buildList(numsB);
    ListNode *headC = buildList(numsC);
    headA->next->next = headC;
    headB->next->next->next = headC;
    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(headA, headB);
    cout << intersection->val << " " << boolalpha << (intersection == headC) << endl;
    destroyList(headA);
    destroyList(headB);
    destroyList(headC);
}