//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"
/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if(nums.size() < 4) {
            return {};
        }
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n-3; ++i) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) { // min sum
                break;
            }
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) { // max sum
                continue;
            }
            for(int j = i+1; j < n-2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) { // min sum
                    break;
                }
                if(nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) { // max sum
                    continue;
                }
                int left = j+1, right = n-1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while(left < right && nums[left] == nums[left-1]) {
                            ++left;
                        }
                        while(right > left && nums[right] == nums[right+1]) {
                            --right;
                        }
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto res = Solution().fourSum(nums, target);
    printMatrix(res);
    return 0;
}