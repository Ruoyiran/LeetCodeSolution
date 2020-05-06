//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root) >= 0;
    }

private:
    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        if (left < 0 || right < 0 || std::abs(left-right) > 1) {
            return -1;
        }
        return std::max(left, right) + 1;
    }
};

int main() {
    vector<int> nums = {3,9,20,-1,-1,15,7};
    auto root = buildTree(nums);
    std::cout << Solution().isBalanced(root) << std::endl;
    destroyTree(root);
    return 0;
}