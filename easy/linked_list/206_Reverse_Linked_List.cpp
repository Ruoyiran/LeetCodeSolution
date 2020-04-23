//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"

// 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *tmpNode = head->next;
            head->next = newHead;
            newHead = head;
            head = tmpNode;
        }
        return newHead;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = buildList(nums);
    printList(head);
    ListNode *newHead = Solution().reverseList(head);
    printList(newHead);
    return 0;
}