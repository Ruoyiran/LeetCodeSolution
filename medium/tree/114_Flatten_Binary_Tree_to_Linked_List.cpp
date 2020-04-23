//
// Created by ranpeng on 2020/4/16.
//
#include "common.h"

/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 */
class Solution {
public:
    void flattenV1(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        TreeNode* rootBak = root;
        stack<TreeNode*> s;
        TreeNode* last = NULL;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                s.push(root);
                last = root;
                root = root->left;
            } else {
                auto node = s.top(); s.pop();
                last->left = node->right;
                node->right = NULL;
                root = last->left;
            }
        }
        while (rootBak != NULL) {
            auto tmp = rootBak->left;
            rootBak->left = rootBak->right;
            rootBak->right = tmp;
            rootBak = rootBak->right;
        }
    }

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top(); s.pop();
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
            node->left = NULL;
            if (!s.empty()) {
                node->right = s.top();
            }
        }
    }
};

int main() {
    vector<int> nums = {1,2,5,3,4,-1,6};
    auto root = buildTree(nums);
    Solution().flatten(root);
    printTreeLevel(root);
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
    return 0;
}