//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
 */
class Solution {
public:
    bool compareTreeV1(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        return (root1->val == root2->val) &&
                compareTreeV1(root1->left, root2->right) &&
                compareTreeV1(root1->right, root2->left);
    }

    bool compareTree(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty()) {
            TreeNode *node1 = q.front(); q.pop();
            TreeNode *node2 = q.front(); q.pop();
            if (node1 == NULL && node2 == NULL) {
                continue;
            }
            if (node1 == NULL || node2 == NULL) {
                return false;
            }
            if (node1->val != node2->val) {
                return false;
            }
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return compareTree(root, root);
    }
};

int main() {
    vector<int> nums = {1,2,2,3,4,4,3};
    int i = 0;
    TreeNode *root = buildTree(nums);
    cout << "root: " << root->val << endl;
    cout << "root->left: " << root->left->val << endl;
    cout << "root->right: " << root->right->val << endl;
    cout << "root->left->left: " << root->left->left->val << endl;
    cout << "root->left->right: " << root->left->right->val << endl;
    cout << "root->right->left: " << root->right->left->val << endl;
    cout << "root->right->right: " << root->right->right->val << endl;
    printTreePreOrder(root);
    cout << endl;
    printTreeTailOrder(root);
    cout << endl;
    printTreeInOrder(root);
    cout << endl;
    Solution solution;
    cout << solution.isSymmetric(root);
    destroyTree(root);
    return 0;
}