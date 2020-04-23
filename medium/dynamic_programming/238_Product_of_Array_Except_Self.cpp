//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of
all the elements of nums except nums[i].

Example:

Input:
[1,2,3,4]

Output:
[24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of
space complexity analysis.)
*/
class Solution {
public:
    vector<int> productExceptSelfV1(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> dp1(nums.size());
        vector<int> dp2(nums.size());
        dp1[0] = nums[0];
        dp2[nums.size()-1] = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); ++i) {
            dp1[i] = dp1[i-1] * nums[i];
        }
        for (int j = nums.size()-2; j >= 0; --j) {
            dp2[j] = dp2[j+1] * nums[j];
        }
        vector<int> results(nums.size());
        results[0] = dp2[1];
        for (int i = 1; i < nums.size()-1; ++i) {
            results[i] = dp1[i-1] * dp2[i+1];
        }
        results[nums.size()-1] = dp1[nums.size()-2];
        return results;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] * nums[i - 1];
        }
        int preProduct = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            dp[i] *= preProduct;
            preProduct *= nums[i];
        }
        return dp;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution solution;
    auto results = solution.productExceptSelf(nums);
    printVector(results);
    return 0;
}