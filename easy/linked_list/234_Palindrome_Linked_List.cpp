//
// Created by ranpeng on 2020/4/13.
//
#include "common.h"

/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = getListLength(head);
        ListNode *head1 = head;
        for (int i = 0; i < len/2; ++i) {
            head = head->next;
        }
        ListNode *head2 = reverseList(head);
        for (int i = 0; i < len/2; ++i) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};

int main() {
    vector<int> nums = {1,0,0, 1};
    ListNode *head = buildList(nums);
    Solution solution;
    cout << solution.isPalindrome(head) << endl;
}