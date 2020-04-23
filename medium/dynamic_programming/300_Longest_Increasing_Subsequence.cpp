//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one
LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n^2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
 */
class Solution {
public:
    // DP O(n^2)
    int lengthOfLISV1(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 0;
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j]);
                }
            }
            dp[i] += 1;
            max = std::max(dp[i], max);
        }
        return max;
    }

    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // binary search O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int pos = binarySearch(dp, nums[i]);
            if (pos >= dp.size()) {
                dp.push_back(nums[i]);
            } else {
                dp[pos] = nums[i];
            }
        }
        return dp.size();
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums);
    return 0;
}