//
// Created by ranpeng on 2020/4/15.
//
#include "common.h"

/*
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
[[3], [9,20], [15,7]]
 */
class Solution {
public:
    struct TreeNodeLevel {
        TreeNode* node;
        int level;
        TreeNodeLevel(TreeNode* node, int level) {
            this->node = node;
            this->level = level;
        }
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNodeLevel> q;
        q.push(TreeNodeLevel(root, 1));
        vector<TreeNodeLevel> nodes;
        int maxLevel = 1;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            nodes.push_back(t);
            if (t.node == NULL) {
                continue;
            }
            maxLevel = std::max(maxLevel, t.level);
            q.push(TreeNodeLevel(t.node->left, t.level+1));
            q.push(TreeNodeLevel(t.node->right, t.level+1));
        }
        int end = nodes.size()-1;
        while (end >= 0 && nodes[end].node == NULL) {
            --end;
        }
        vector<vector<int>> results(maxLevel);
        for (int i = 0; i <= end; ++i) {
            if (nodes[i].node == NULL) {
                continue;
            }
            results[nodes[i].level-1].push_back(nodes[i].node->val);
        }
        return results;
    }
};

int main() {
    vector<int> nums = {1,2,-1,3,-1,4,-1,5};
    auto root = buildTree(nums);
    auto results = Solution().levelOrder(root);
    for (auto& r : results) {
        printVector(r);
    }
    printTreeLevel(root);
    destroyTree(root);
    return 0;
}
