//
// Created by ranpeng on 2020/4/14.
//
#include "common.h"

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> find;
        int sum = 0;
        backtracking(candidates, find, sum, target, results, 0);
        return results;
    }

    void backtracking(const vector<int>& candidates, vector<int>& find, int sum, int target, vector<vector<int>>& results, int start) {
        if (sum > target) {
             return;
        }
        if (sum == target) {
            results.push_back(find);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            int c = candidates[i];
            find.push_back(c);
            backtracking(candidates, find, sum+c, target, results, i);
            find.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {2,4,6,8};
    int target = 8;
    Solution solution;
    auto results = solution.combinationSum(nums, target);
    for (auto r : results) {
        printVector(r);
    }
    return 0;
}