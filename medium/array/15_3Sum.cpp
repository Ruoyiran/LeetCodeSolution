//
// Created by ranpeng on 2020/4/13.
//

#include <sstream>
#include "common.h"

/*
Given an array nums of n integers, are three elements a, b, c in nums such that a+b+c=0? Find all unique triplets in the
array which gives the sum of zero.
Note：
The solution set must not contain duplicate triplets.
Example：
> Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[[-1, 0, 1],[-1, -1, 2]]
 */
class Solution {
public:
    // Time Limit Exceeded O(n^3)
    vector<vector<int>> threeSumV1(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < nums.size()-1; ++j) {
                for (int k = j+1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> vec = {nums[i], nums[j], nums[k]};
                        results.push_back(vec);
                    }
                }
            }
        }
        return results;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        int n = nums.size();
        int t = 0;
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = t - nums[i];
            if (nums[i+1] + nums[i+2] > target) { // min value
                break;
            }
            if (nums[n-1] + nums[n-2] < target) { // max value
                continue;
            }
            int left = i+1, right = n-1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    results.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left-1]) ++left;
                    while (left < right && nums[right] == nums[right+1]) --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return results;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution;
    auto results = solution.threeSum(nums);
    for (auto vec : results) {
        printVector(vec);
    }
}
