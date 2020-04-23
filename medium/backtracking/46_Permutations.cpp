//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"

/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        backtracking(nums, 0, results);
        return results;
    }

    void backtracking(vector<int>& nums, int index, vector<vector<int>> &results) {
        if (index == nums.size()) {
            results.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            swap(nums, i, index);
            backtracking(nums, index + 1, results);
            swap(nums, i, index);
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    auto results = Solution().permute(nums);
    for (auto r : results) {
        printVector(r);
    }
    return 0;
}