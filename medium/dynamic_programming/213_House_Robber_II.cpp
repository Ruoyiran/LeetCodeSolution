//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not
get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the
neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

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
        return std::max(rob(nums.begin()+1, nums.end()),
                        rob(nums.begin(), nums.end()-1));
    }

private:
    int rob(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin >= end) {
            return 0;
        }
        if (end-begin == 1) {
            return *begin;
        }
        if (end-begin == 2) {
            return std::max(*begin, *(end-1));
        }
        std::vector<int> dp = {*begin, std::max(*begin, *(begin+1))};
        int max = 0;
        for (auto iter = begin+2; iter != end; ++iter) {
            dp.push_back(std::max(dp[iter-begin-2]+(*iter), dp[iter-begin-1]));
        }
        return dp.back();
    }
};

int main() {
    vector<int> nums = {1,3,1,3,100};
    cout << Solution().rob(nums) << endl;
    return 0;
}