//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 */
class Solution {
public:
    int subarraySumV1(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        int count = 0;
        for (int start = 0; start < sums.size(); ++start) {
            for (int end = start+1; end < sums.size(); ++end) {
                if (sums[end]-sums[start] == k) {
                    ++count;
                }
            }
        }
        return count;
    }

    int subarraySumV2(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) {
                    ++count;
                }
            }
        }
        return count;
    }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, res = 0;
        for (int n : nums) {
            sum += n;
            res += m[sum-k];
            ++m[sum];
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << Solution().subarraySum(nums, k);
    return 0;
}
