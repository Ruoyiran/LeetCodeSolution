//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
class Solution {
public:
    ListNode* sortListV1(ListNode* head) {
        int len = getListLength(head);
        return sortList(head, len);
    }

    ListNode* sortList(ListNode* head, int len) {
        if (len == 0) {
            return NULL;
        }
        if (len == 1) {
            return head;
        }
        auto left = head, right = head;
        ListNode* prev = NULL;
        for (int i = 0; i < len/2; ++i) {
            prev = right;
            right = right->next;
        }
        if (prev) prev->next = NULL;
        auto sorted1 = sortList(left, len/2);
        auto sorted2 = sortList(right, len-len/2);
        return merge(sorted1, sorted2);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        ListNode* headDummy = new ListNode(0);
        ListNode* head = headDummy;
        while (left && right) {
            if (left->val < right->val) {
                head->next = left;
                left = left->next;
            } else {
                head->next = right;
                right = right->next;
            }
            head = head->next;
        }
        if (left) {
            head->next = left;
        }
        if (right) {
            head->next = right;
        }
        head = headDummy->next;
        delete headDummy;
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto mid = slow->next;
        slow->next = NULL;
        auto left = sortList(head);
        auto right = sortList(mid);
        return merge(left, right);
    }
};

int main() {
    vector<int> nums = {-1,5,3,4,0};
    auto head = buildList(nums);
    auto newHead = Solution().sortListV1(head);
    printList(newHead);
    destroyList(newHead);
    return 0;
}
