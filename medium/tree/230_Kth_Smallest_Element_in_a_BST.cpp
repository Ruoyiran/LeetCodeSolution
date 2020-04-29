//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would
you optimize the kthSmallest routine?
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        int res = 0;
        helper(root, k, c, res);
        return res;
    }

    void helper(TreeNode* root, int k, int& count, int& res) {
        if (root) {
            helper(root->left, k, count, res);
            if (++count == k) {
                res = root->val;
            }
            helper(root->right, k, count, res);
        }
    }
};

int main() {
    vector<int> nums = {5,3,6,2,4,-1,-1,1};
    int k = 3;
    auto root = buildTree(nums);
    std::cout << Solution().kthSmallest(root, k) << std::endl;
    destroyTree(root);
    return 0;
}