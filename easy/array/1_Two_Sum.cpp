#include "common.h"

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> values_map;
        for (int i = 0; i < nums.size(); ++i) {
            values_map[nums[i]] = i;
        }
        vector<int> results(2);
        for (int i = 0; i < nums.size(); ++i) {
            int d = target-nums[i];
            auto iter = values_map.find(d);
            if (iter != values_map.end() && iter->second != i) {
                results[0] = i;
                results[1] = iter->second;
                return results;
            }
        }
        return results;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15, -1, 100};
    int target = 107;
    vector<int> results = solution.twoSum(nums, target);
    cout << results[0] << " " << results[1] << endl;
    return 0;
}
