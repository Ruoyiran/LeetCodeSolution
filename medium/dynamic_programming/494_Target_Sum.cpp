//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
You are given a list of non-negative integers, a1, a2, …, an, and a target, S. Now you have 2 symbols + and -. For each
integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
class Solution {
public:
    int findTargetSumWaysV1(vector<int>& nums, int S) {
        int count = 0;
        vector<unordered_map<int, int>> memo(nums.size());
        helper(nums, S, 0, 0, count);
        return count;
    }

    int findTargetSumWaysV2(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> memo(nums.size());
        return helper(nums, S, 0, 0, memo);
    }

    /*
     * 整数数组中选一部分取负，其它不变，问一共有多少种取法能让最后的和等于S。把集合的数看成两个子集，
     * 满足sum(P) - sum(!P) = target 和sum(P) + sum(!P) = sum => sum(P) = (sum + target)/2，
     * 也就是找和为(sum+target)/2的子集数目，01背包。
     */
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) % 2 != 0) {
            return 0;
        }
        int capacity = (sum + S) / 2;
        vector<int> dp(capacity + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int c = capacity; c >= nums[i]; --c) {
                dp[c] += dp[c - nums[i]];
            }
        }
        return dp[capacity];
    }

private:
    void helper(vector<int>& nums, int S, int index, int sum, int& count) {
        if (index >= nums.size()) {
            if (sum == S) {
                ++count;
            }
            return;
        }
        helper(nums, S, index + 1, sum + nums[index], count);
        helper(nums, S, index + 1, sum - nums[index], count);
    }

    int helper(vector<int>& nums, int S, int index, int sum, vector<unordered_map<int, int>> &memo) {
        if (index >= nums.size()) {
            return S == sum ? 1 : 0;
        }
        if (memo[index].count(sum) > 0) {
            return memo[index][sum];
        }
        int count1 = helper(nums, S, index+1, sum+nums[index], memo);
        int count2 = helper(nums, S, index+1, sum-nums[index], memo);
        memo[index][sum] = count1 + count2;
        return count1 + count2;
    }
};

int main() {
    vector<int> nums = {1,1,1,1,1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;
    return 0;
}