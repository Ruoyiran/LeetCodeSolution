//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q, next;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            vector<int> level;
            while (!q.empty()) {
                auto node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) {
                    next.push(node->left);
                }
                if (node->right) {
                    next.push(node->right);
                }
            }
            if (!flag) {
                std::reverse(level.begin(), level.end());
            }
            flag = !flag;
            q.swap(next);
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3,9,20,-1,-1,15,7};
    auto root = buildTree(nums);
    auto res = Solution().zigzagLevelOrder(root);
    printMatrix(res);
    destroyTree(root);
    return 0;
}