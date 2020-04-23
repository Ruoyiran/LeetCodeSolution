//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> nums;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                s.push(root);
                root = root->left;
                continue;
            }
            auto node = s.top(); s.pop();
            nums.push_back(node->val);
            root = node->right;
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {1,-1,2,3};
    auto root = buildTree(nums);
    printTreeInOrder(root);
    Solution solution;
    auto results = solution.inorderTraversal(root);
    cout << endl;
    printVector(results);
    destroyTree(root);
    return 0;
}