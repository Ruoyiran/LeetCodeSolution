//
// Created by 冉鹏 on 2020/5/6.
//
#include "common.h"

/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while (!s.empty()) {
            auto node = s.top(); s.pop();
            res.push_back(node->val);
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,-1,2,3,1,2,3,4};
    auto root = buildTree(nums);
    auto res = Solution().preorderTraversal(root);
    printVector(res);
    destroyTree(root);
    return 0;
}