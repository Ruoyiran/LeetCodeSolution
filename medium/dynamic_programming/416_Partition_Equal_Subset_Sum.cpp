//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such
that the sum of elements in both subsets is equal.

Note:
Both the array size and each of the array element will not exceed 100.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) {
            return false;
        }
        // Knapsack01
        int capacity = (sum >> 1);
        vector<bool> dp(capacity + 1, false);
        // 当只放一个物品时，每个容量的背包是否放得下
        for (int i = 1; i <= capacity; ++i) {
            dp[i] = nums[0] == i;
        }
        // 计算当放前i个物品时，背包容量为c，是否放得下
        for (int i = 1; i < nums.size(); ++i) {
            for (int c = capacity; c >= nums[i]; --c) {
                dp[c] = dp[c] || dp[c-nums[i]];
            }
        }
        return dp[capacity];
    }
};

int main() {
    vector<int> nums = {23,13,11,7,6,5,5};
    cout << Solution().canPartition(nums);
    return 0;
}
