//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> results;
        for (int l = 0; l <= nums.size(); ++l) {
            backtracking(nums, subset, 0, l, results);
        }
        return results;
    }

    void backtracking(const vector<int>& nums, vector<int>& subset, int start, int len, vector<vector<int>>& results) {
        if (len > nums.size()) {
            return;
        }
        if (len == subset.size()) {
            results.push_back(subset);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtracking(nums, subset, i+1, len, results);
            subset.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    auto results = Solution().subsets(nums);
    for (auto &r: results) {
        printVector(r);
    }
    return 0;
}