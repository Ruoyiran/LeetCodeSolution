//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the
parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT32_MIN;
        helper(root, maxSum);
        return maxSum;
    }

private:
    int helper(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return 0;
        }
        int left = std::max(0, helper(root->left, maxSum));
        int right = std::max(0, helper(root->right, maxSum));
        maxSum = std::max(maxSum, left+right+root->val);
        return std::max(left, right) + root->val;
    }
};

int main() {
    vector<int> nums = {-1,-2,-3};
    TreeNode *root = buildTree(nums, -1);
    cout << Solution().maxPathSum(root) << endl;
    destroyTree(root);
    return 0;
}