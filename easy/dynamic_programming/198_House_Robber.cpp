//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
money you can rob tonight without alerting the police.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
//        std::vector<int> dp = {nums[0], std::max(nums[0], nums[1])};
        int t1 = nums[0];
        int t2 = std::max(nums[0], nums[1]);
        int max = 0;
        for (int i = 2; i < nums.size(); ++i) {
//            dp.push_back(std::max(dp[i-2]+nums[i], dp[i-1]));
            max = std::max(t1 + nums[i], t2);
            t1 = t2;
            t2 = max;
        }
//        return dp.back();
        return max;
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << Solution().rob(nums) << endl;
    return 0;
}