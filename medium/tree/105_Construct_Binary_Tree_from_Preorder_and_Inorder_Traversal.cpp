//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        return helper(preorder, inorder, start, 0, inorder.size()-1);
    }

    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder, int &preorderStart, int inorderStart, int inorderEnd) {
        if (preorderStart >= preorder.size() ||
                inorderStart > inorderEnd) {
            return NULL;
        }
        auto root = new TreeNode(preorder[preorderStart++]);
        for (int i = inorderStart; i <= inorderEnd; ++i) {
            if (inorder[i] == root->val) {
                root->left = helper(preorder, inorder, preorderStart, inorderStart, i-1);
                root->right = helper(preorder, inorder, preorderStart, i+1, inorderEnd);
            }
        }
        return root;
    }
};

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution solution;
    auto root = solution.buildTree(preorder, inorder);
    printTreeLevel(root);
    destroyTree(root);
}