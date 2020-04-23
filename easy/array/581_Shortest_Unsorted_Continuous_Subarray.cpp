//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Question
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order,
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
 Input: [2, 6, 4, 8, 10, 9, 15]
 Output: 5
 Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 */
class Solution {
public:
    // Time Limit Exceeded O(n^2)
    int findUnsortedSubarrayV1(vector<int>& nums) {
        int start = INT32_MAX;
        int len = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                int j = i;
                while (j > 0 && nums[j] < nums[j-1]) {
                    swap(nums, j, j-1);
                    --j;
                }
                start = std::min(start, j);
                len = i - start + 1;
            }
        }
        return len;
    }

    // O(nlogn)
    int findUnsortedSubarrayV2(vector<int>& nums) {
        vector<int> copied = nums;
        std::sort(copied.begin(), copied.end());
        int i = 0, j = nums.size()-1;
        while (i < nums.size() && copied[i] == nums[i]) {
            ++i;
        }
        while (j > i && copied[j] == nums[j]) {
            --j;
        }
        return j - i + 1;
    }

    // O(n)
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }
        int n = nums.size();
        int max = nums[0];
        int min = nums[n-1];
        int start = -1, end = -2;
        for (int i = 1; i < n; ++i) {
            max = std::max(max, nums[i]);
            if (nums[i] < max) {
                end = i;
            }

            min = std::min(min, nums[n-i-1]);
            if (nums[n-i-1] > min) {
                start = n - i - 1;
            }
        }
        return end - start + 1;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution solution;
    cout << solution.findUnsortedSubarray(nums) << endl;
    return 0;
}