//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
 root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
 */
class Solution {
private:
    struct NodeSum {
        TreeNode* node;
        int sum;
        NodeSum(TreeNode *node, int sum) {
            this->node = node;
            this->sum = sum;
        }
    };

public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int total = 0;
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            findPath(node, sum, total);
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        return total;
    }

    void findPath(TreeNode* root, int sum, int &total) {
        if (root == NULL) {
            return;
        }
        if (root->val == sum) {
            total += 1;
        }
        findPath(root->left, sum-root->val, total);
        findPath(root->right, sum-root->val, total);
    }

    int pathSumV2(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        stack<NodeSum> s;
        queue<TreeNode*> q;
        q.push(root);
        int total = 0;
        // BFS + DFS
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            s.push(NodeSum(node, node->val));
            while (!s.empty()) {
                auto t = s.top(); s.pop();
                if (t.sum == sum) {
                    total += 1;
                }
                if (t.node->left != NULL) {
                    s.push(NodeSum(t.node->left, t.sum + t.node->left->val));
                }
                if (t.node->right != NULL) {
                    s.push(NodeSum(t.node->right, t.sum + t.node->right->val));
                }
            }
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        return total;
    }
};

int main() {
    vector<int> nums = {10,5,-3,3,2,-100,11,3,-2,-100,1};
    int sum = 8;
    TreeNode *root = buildTree(nums, -100);
//    printTreeLevel(root);
//    cout << endl;
    Solution solution;
    int total = solution.pathSum(root, sum);
    cout << "total: " << total << endl;
    destroyTree(root);
    return 0;
}