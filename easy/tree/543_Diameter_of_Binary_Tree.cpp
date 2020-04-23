//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        findDepth(root, depth);
        return depth;
    }

    int findDepth(TreeNode *root, int &depth) {
        if (root == NULL) {
            return 0;
        }
        int left = findDepth(root->left, depth);
        int right = findDepth(root->right, depth);
        depth = std::max(depth, left+right);
        return std::max(left, right) + 1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(nums);
    cout << Solution().diameterOfBinaryTree(root) << endl;
    return 0;
}