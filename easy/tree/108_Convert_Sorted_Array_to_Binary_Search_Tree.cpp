//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums.begin(), nums.end());
    }

private:
    TreeNode *helper(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin >= end) {
            return NULL;
        }
        auto mid = begin + (end-begin)/2;
        auto root = new TreeNode(*mid);
        root->left = helper(begin, mid);
        root->right = helper(mid+1, end);
        return root;
    }
};

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    auto root = Solution().sortedArrayToBST(nums);
    printTreeLevel(root);
    destroyTree(root);
    return 0;
}