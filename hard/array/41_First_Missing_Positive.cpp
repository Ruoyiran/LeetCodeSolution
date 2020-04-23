//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
 */
class Solution {
public:
    int firstMissingPositiveV1(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); ++i) {
            if (s.find(i) == s.end()) {
                return i;
            }
        }
        return 1;
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i]-1);
            }
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i-1] != i) {
                return i;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    vector<int> nums = {3,4,-1,1};
    cout << Solution().firstMissingPositive(nums) << endl;
    return 0;
}
