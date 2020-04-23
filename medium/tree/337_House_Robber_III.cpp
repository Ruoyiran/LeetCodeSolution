//
// Created by ranpeng on 2020/4/17.
//
#include "common.h"

/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the “root.”
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that “all houses
in this place forms a binary tree”. It will automatically contact the police if two directly-linked houses were broken
into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
 3
/ \
2  3
 \  \
  3  1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
    3
   / \
  4   5
 / \   \
1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
 */
class Solution {
public:
    int robV1(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = 0;
        int subLeft = 0;
        if (root->left != NULL) {
            left = robV1(root->left);
            subLeft = robV1(root->left->left) + robV1(root->left->right);
        }

        int right = 0;
        int subRight = 0;
        if (root->right != NULL) {
            right = robV1(root->right);
            subRight = robV1(root->right->left) + robV1(root->right->right);
        }

        return std::max(left+right, root->val + subLeft + subRight);
    }

    int robV2(TreeNode* root) {
        unordered_map<TreeNode*, int> cache;
        return helper(root, cache);
    }

    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return std::max(res[0], res[1]);
    }

private:
    //returns arr[2]
    //arr[0] is maximum amount of money can be robbed if root is robbed
    //arr[1] is maximum amount of money can be robbed if root is not robbed
    vector<int> helper(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);

        int maxAmountRobRoot = root->val + left[1] + right[1];
        int maxAmountNotRobRoot = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        return {maxAmountRobRoot, maxAmountNotRobRoot};
    }

    int helper(TreeNode* root, unordered_map<TreeNode*, int> &cache) {
        if (root == NULL) {
            return 0;
        }
        if (cache.find(root) != cache.end()) {
            return cache[root];
        }
        int left = 0;
        int subLeft = 0;
        if (root->left != NULL) {
            left = robV1(root->left);
            subLeft = robV1(root->left->left) + robV1(root->left->right);
        }

        int right = 0;
        int subRight = 0;
        if (root->right != NULL) {
            right = robV1(root->right);
            subRight = robV1(root->right->left) + robV1(root->right->right);
        }

        int max = std::max(left+right, root->val + subLeft + subRight);
        cache[root] = max;
        return max;
    }
};

int main() {
    vector<int> nums = {3,2,3,-1,3,-1,1};
    auto root = buildTree(nums);
    cout << Solution().rob(root);
    destroyTree(root);
}
