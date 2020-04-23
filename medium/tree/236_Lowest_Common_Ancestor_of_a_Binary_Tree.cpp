//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the
lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        }
        return left ? left : right;
    }
};

int main() {
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    auto root = buildTree(nums);
    auto p = root->left;
    auto q = root->left->right->right;
    auto lca = Solution().lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        cout << lca->val << endl;
    }
    destroyTree(root);
    return 0;
}
