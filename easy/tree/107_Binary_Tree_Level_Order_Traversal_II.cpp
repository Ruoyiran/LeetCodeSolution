//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> q, next;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> levels;
            while (!q.empty()) {
                auto node = q.front(); q.pop();
                if (node->left) {
                    next.push(node->left);
                }
                if (node->right) {
                    next.push(node->right);
                }
                levels.push_back(node->val);
            }
            res.push_back(levels);
            q.swap(next);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> nums = {3,9,20,-1,-1,15,7};
    auto root = buildTree(nums);
    auto res = Solution().levelOrderBottom(root);
    printMatrix(res);
    destroyTree(root);
    return 0;
}