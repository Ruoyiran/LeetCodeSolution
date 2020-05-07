//
// Created by 冉鹏 on 2020/5/6.
//
#include "common.h"

/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k < 1 || n < 1) {
            return {};
        }
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i+1;
        }
        vector<int> candidates;
        vector<vector<int>> res;
        helper(nums, k, 0, candidates, res);
        return res;
    }

private:
    void helper(const vector<int> &nums, int k, int start, vector<int> &candidates, vector<vector<int>> &results) {
        if (candidates.size() == k) {
            results.push_back(candidates);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            candidates.push_back(nums[i]);
            helper(nums, k, i+1, candidates, results);
            candidates.pop_back();
        }
    }
};

int main() {
    auto res = Solution().combine(10, 3);
    printMatrix(res);
    return 0;
}