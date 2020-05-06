//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

1
/ \
2 3
/ \
4 5
as “[1,2,3,#,#,4,5]”, just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> allNodes;
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            allNodes.push_back(node);
            if (node == NULL) {
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        while (allNodes[allNodes.size()-1] == NULL) {
            allNodes.resize(allNodes.size()-1);
        }
        stringstream ss;
        for (int i = 0; i < allNodes.size(); ++i) {
            auto node = allNodes[i];
            if (node != NULL) {
                ss << node->val;
            } else {
                ss << "#";
            }
            if (i != allNodes.size()-1) {
                ss << ",";
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values;
        splitString(data, values);
        return buildTree(values);
    }

private:
    TreeNode* buildTree(const vector<string>& values) {
        if (values.empty()) {
            return NULL;
        }
        auto root = new TreeNode(std::stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < values.size()) {
            auto node = q.front(); q.pop();
            if (values[i] == "#") {
                node->left = NULL;
            } else {
                node->left = new TreeNode(std::stoi(values[i]));
                q.push(node->left);
            }
            ++i;
            if (i >= values.size()) {
                break;
            }
            if (values[i] == "#") {
                node->right = NULL;
            } else {
                node->right = new TreeNode(std::stoi(values[i]));
                q.push(node->right);
            }
            ++i;
        }
        return root;
    }
};

int main() {
    vector<int> nums = {1,2,3,-1,-1,4,5};
    auto root = buildTree(nums);
    auto c = Codec();
    auto s = c.serialize(root);
    cout << "serialize: " << s << endl;
    auto newRoot = c.deserialize(s);
    cout << "deserialize: ";
    printTreeBFS(newRoot);
    destroyTree(newRoot);
    destroyTree(root);
}
