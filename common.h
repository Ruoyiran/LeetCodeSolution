//
// Created by ranpeng on 2020/4/12.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <functional>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct NodeSum {
    TreeNode* node;
    int sum;
    NodeSum(TreeNode *node, int sum) {
        this->node = node;
        this->sum = sum;
    }
};

void swap(vector<int>& nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void swap(vector<vector<int>>& nums, pair<int, int> pos1, pair<int, int> pos2) {
    int t = nums[pos1.first][pos1.second];
    nums[pos1.first][pos1.second] = nums[pos2.first][pos2.second];
    nums[pos2.first][pos2.second] = t;
}

int getListLength(ListNode *head) {
    int len = 0;
    while (head != NULL) {
        ++len;
        head = head->next;
    }
    return len;
}

ListNode* reverseList(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *newHead = NULL;
    while (head != NULL) {
        ListNode *tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}

ListNode* buildList(const vector<int> &vals) {
    ListNode* dummyNode = new ListNode(0);
    ListNode* pHead = dummyNode;
    for (int v : vals) {
        pHead->next = new ListNode(v);
        pHead = pHead->next;
    }
    pHead = dummyNode->next;
    delete dummyNode;
    return pHead;
}

template <typename T>
void printVector(const vector<T> &nums, const std::string& sep) {
    for (const T& v : nums) {
        cout << v << sep;
    }
    if (!nums.empty()) {
        cout << endl;
    }
}

template <typename T>
void printMatrix(const vector<vector<T>> &matrix, const std::string& sep) {
    for (const vector<T>& row : matrix) {
        printVector<T>(row, sep);
    }
}

template <typename T = int>
void printVector(const vector<int> &nums, const std::string& sep=" ") {
    for (int v : nums) {
        cout << v << sep;
    }
    if (!nums.empty()) {
        cout << endl;
    }
}

template <typename T = int>
void printMatrix(const vector<vector<int>> &matrix, const std::string& sep = " ") {
    for (const vector<int>& row : matrix) {
        printVector(row, sep);
    }
}

template <typename T = char>
void printMatrix(const vector<vector<char>> &matrix, const std::string& sep = " ") {
    for (const vector<char>& row : matrix) {
        printVector(row, sep);
    }
}

void printList(ListNode *list) {
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

void destroyList(ListNode *list) {
    while (list != NULL) {
        ListNode *temp = list->next;
        delete list;
        list = temp;
    }
}

void printTreePreOrder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(TreeNode* root) {
    if (root) {
        printTreeInOrder(root->left);
        cout << root->val << " ";
        printTreeInOrder(root->right);
    }
}

void printTreeTailOrder(TreeNode* root) {
    if (root) {
        printTreeTailOrder(root->left);
        printTreeTailOrder(root->right);
        cout << root->val << " ";
    }
}

void printTreeBFS(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        cout << node->val << " ";
        q.pop();
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
    cout << endl;
}

int getTreeLevel(int num) {
    if (num < 1) {
        return 0;
    }
    int level = 1;
    while (num > 1) {
        num /= 2;
        ++level;
    }
    return level;
}

void printTreeLevelV2(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> curr, next;
    curr.push(root);
    while (!curr.empty()) { // BFS
        while (!curr.empty()) {
            auto node = curr.front(); curr.pop();
            std::cout << node->val;
            if (node->next) {
                std::cout << " # ";
            } else {
                std::cout << " ";
            }
            if (node->left) {
                next.push(node->left);
            }
            if (node->right) {
                next.push(node->right);
            }
        }
        curr.swap(next);
        std::cout <<std::endl;
    }
}

void printTreeLevel(TreeNode* root) {
    struct TreeNodeLevel {
        TreeNode* node;
        int level;
        TreeNodeLevel(TreeNode* node, int level) {
            this->node = node;
            this->level = level;
        }
    };
    if (root == NULL) {
        return;
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
    int preLevel = 1;
    for (int i = 0; i <= end; ++i) {
        if (preLevel != nodes[i].level) {
            preLevel = nodes[i].level;
            cout << endl;
        }
        if (nodes[i].node == NULL) {
            cout << "null ";
        } else {
            cout << nodes[i].node->val << " ";
        }
    }
    cout << endl;
}

void destroyTree(TreeNode *root) {
    if (root) {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        delete root;
        destroyTree(left);
        destroyTree(right);
    }
}

// BFS
TreeNode* buildTree(const vector<int>& nums, int nullValue = -1) {
    queue<TreeNode*> q;
    int i = 0;
    auto *root = new TreeNode(nums[i]);
    q.push(root); ++i;
    while (i < nums.size()) {
        TreeNode *node = q.front(); q.pop();
        if (nums[i] == nullValue) {
            node->left = NULL;
        } else {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        ++i;
        if (i < nums.size()) {
            if (nums[i] == nullValue) {
                node->right = NULL;
            } else {
                node->right = new TreeNode(nums[i]);
                q.push(node->right);
            }
        }
        ++i;
    }
    return root;
}

void splitString(const std::string& s, vector<string>& res, const std::string& sep = ",") {
    res.clear();
    if (s.empty()) {
        return;
    }
    int start = 0, end = 0;
    while ((end = s.find(sep, start)) != string::npos) {
        res.push_back(s.substr(start, end-start));
        start = end+1;
    }
    res.push_back(s.substr(start, s.size()-start));
}
#endif //LEETCODE_COMMON_H
