//
// Created by ranpeng on 2020/4/19.
//
#include "common.h"

/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> a(n);
        a[0] = 1;
        a[n - 1] = 1;
        std::copy(nums.begin(), nums.end(), a.begin()+1);
        // 设dp[i][j]为i到j这段区间所能得到的最大值，
        // 状态转移方程为dp[i][j] = max(i < k < j) (dp[i][k] + dp[k][j] + a[i] * a[k] * a[j])
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    vector<int> nums = {3,1,5,8};
    cout << Solution().maxCoins(nums) << endl;
    return 0;
}