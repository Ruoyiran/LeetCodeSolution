//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

给出一个二叉树，找出它的最大深度
 */
class Solution {
public:
    struct TreeNodeHelper {
        TreeNode* treeNode;
        int depth;
        TreeNodeHelper(TreeNode* node, int d) {
            treeNode = node;
            depth = d;
        }
    };

    int maxDepthV1(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return std::max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        stack<TreeNodeHelper> s;
        s.push(TreeNodeHelper(root, 1));
        int maxDep = 1;
        while (!s.empty()) {
            auto node = s.top(); s.pop();
            maxDep = std::max(maxDep, node.depth);
            if (node.treeNode->left != NULL) {
                s.push(TreeNodeHelper(node.treeNode->left, node.depth+1));
            }
            if (node.treeNode->right != NULL) {
                s.push(TreeNodeHelper(node.treeNode->right, node.depth+1));
            }
        }
        return maxDep;
    }
};

int main() {
    vector<int> nums = {3,9,20,-1,-1,15,7};
    TreeNode *root = buildTree(nums);
    Solution solution;
    cout << solution.maxDepth(root);
    destroyTree(root);
}