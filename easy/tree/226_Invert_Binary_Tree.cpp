//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"

/*
 invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
 */
class Solution {
public:
    TreeNode* invertTreeV1(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        auto left = invertTree(root->right);
        auto right = invertTree(root->left);
        root->left =  left;
        root->right = right;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            auto tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        return root;
    }
};

int main() {
    vector<int> nums = {4,2,7,1,3,6,9};
    TreeNode *root = buildTree(nums);
    printTreeBFS(root);
    printTreeBFS(Solution().invertTree(root));
    return 0;
}
