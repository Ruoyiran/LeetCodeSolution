//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestorV1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root) {
            return root;
        }
        auto left = lowestCommonAncestorV1(root->left, p, q);
        auto right = lowestCommonAncestorV1(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        }
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else {
                break;
            }
        }
        return root;
    }
};

int main() {
    vector<int> nums = {6,2,8,0,4,7,9,-1,-1,3,5};;
    auto root = buildTree(nums);
    auto p = root->left;
    auto q = root->right;
    auto t = Solution().lowestCommonAncestor(root, p, q);
    std::cout << t->val << std::endl;
    return 0;
}