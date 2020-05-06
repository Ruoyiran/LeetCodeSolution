//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            if (node1 != NULL && node2 == NULL) {
                return false;
            }
            if (node1 == NULL && node2 != NULL) {
                return false;
            }
            if (node1 == NULL && node2 == NULL) {
                continue;
            }
            if (node1->val != node2->val) {
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    auto tree1 = buildTree(nums);
    auto tree2 = buildTree(nums);
    std::cout << Solution().isSameTree(tree1, tree2) << std::endl;
    destroyTree(tree1);
    destroyTree(tree2);
    return 0;
}