//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are
overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as
the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 */
class Solution {
public:
    TreeNode* mergeTreesV1(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        auto root = new TreeNode(0);
        merge(root, t1);
        merge(root, t2);
        return root;
    }

    void merge(TreeNode* t1, TreeNode* t2) {
        if (t2 != NULL) {
            t1->val += t2->val;
            if (t1->left == NULL && t2->left != NULL) {
                t1->left = new TreeNode(0);
            }
            if (t1->right == NULL && t2->right != NULL) {
                t1->right = new TreeNode(0);
            }
            merge(t1->left, t2->left);
            merge(t1->right, t2->right);
        }
    }

    TreeNode* mergeTreesV2(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTreesV2(t1->left, t2->left);
        t1->right = mergeTreesV2(t1->right, t2->right);
        return t1;
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        queue<TreeNode*> q;
        q.push(t1);
        q.push(t2);
        while (!q.empty()) {
            auto node1 = q.front(); q.pop();
            auto node2 = q.front(); q.pop();
            if (node1 == NULL || node2 == NULL) {
                continue;
            }
            node1->val += node2->val;
            if (node1->left == NULL) {
                node1->left = node2->left;
            } else {
                q.push(node1->left);
                q.push(node2->left);
            }

            if (node1->right == NULL) {
                node1->right = node2->right;
            } else {
                q.push(node1->right);
                q.push(node2->right);
            }
        }
        return t1;
    }
};

int main() {
    vector<int> nums1 = {1,3,2,5};
    vector<int> nums2 = {2,1,3,-1,4,-1,7};
    auto tree1 = buildTree(nums1);
    auto tree2 = buildTree(nums2);
    Solution solution;
    auto tree3 = solution.mergeTrees(tree1, tree2);
    printTreeLevel(tree3);
    destroyTree(tree3);
    return 0;
}