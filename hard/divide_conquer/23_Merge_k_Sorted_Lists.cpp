//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size()-1);
    }

private:
    ListNode* helper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return NULL;
        }
        if (start == end) {
            return lists[start];
        }
        int mid = (start+end)/2;
        auto left = helper(lists, start, mid);
        auto right = helper(lists, mid+1, end);
        return merge(left, right);
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
};

int main() {
    vector<vector<int>> nums = {
            {1,4,5},
            {1,3,4},
            {2,6},
    };
    vector<ListNode*> lists;
    for(auto& subNums : nums) {
        lists.push_back(buildList(subNums));
    }
    auto res = Solution().mergeKLists(lists);
    printList(res);
    destroyList(res);
    return 0;
}
