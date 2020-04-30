//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking
about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        auto oddNodeDummy = new ListNode(0);
        auto evenNodeDummy = new ListNode(0);
        auto oddNode = oddNodeDummy;
        auto evenNode = evenNodeDummy;
        int i = 1;
        while (head != NULL) {
            if (i & 0x1) {
                oddNode->next = head;
                oddNode = oddNode->next;
            } else {
                evenNode->next = head;
                evenNode = evenNode->next;
            }
            head = head->next;
            ++i;
        }
        oddNode->next = evenNodeDummy->next;
        evenNode->next = NULL;
        head = oddNodeDummy->next;
        delete oddNodeDummy;
        delete evenNodeDummy;
        return head;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    auto head = buildList(nums);
    printList(head);
    head = Solution().oddEvenList(head);
    printList(head);
    destroyList(head);
    return 0;
}