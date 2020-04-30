//
// Created by ranpeng on 2020/4/30.
//

#include "common.h"

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> res(nums.size());
        TreeNode* root = new TreeNode(nums[nums.size()-1]);
        for (int i = nums.size()-2; i >= 0; --i) {
            res[i] = addNode(root, nums[i]);
        }
        destroyTree(root);
        return res;
    }

private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        int count;
        TreeNode(int x) : val(x), left(NULL), right(NULL), count(1) {}
    };

    int addNode(TreeNode *root, int val) {
        int count = 0;
        while (true) {
            if (val <= root->val) {
                ++root->count;
                if (root->left == NULL) {
                    root->left = new TreeNode(val);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                count += root->count;
                if (root->right == NULL) {
                    root->right = new TreeNode(val);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return count;
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
};

int main() {
    vector<int> nums = {5,2,6,1};
    auto res = Solution().countSmaller(nums);
    printVector(res);

    nums = {-1, -1};
    res = Solution().countSmaller(nums);
    printVector(res);
    return 0;
}
