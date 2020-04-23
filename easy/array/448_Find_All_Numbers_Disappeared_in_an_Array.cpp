//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
 */
class Solution {
public:
    vector<int> findDisappearedNumbersV1(vector<int>& nums) {
        vector<int> disappeared;
        for (int i = 0; i < nums.size(); ++i) {
            int t = nums[i];
            while (nums[t-1] != t) {
                swap(nums, t-1, i);
                t = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                disappeared.push_back(i+1);
            }
        }
        return disappeared;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappeared;
        for (int i = 0; i < nums.size(); ++i) {
            int t = std::abs(nums[i]) - 1;
            if (nums[t] > 0) {
                nums[t] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                disappeared.push_back(i+1);
            }
        }
        return disappeared;
    }
};

int main() {
    vector<int> nums = {1,2,3,3,5,7,7};
    Solution solution;
    vector<int> results = solution.findDisappearedNumbers(nums);
    printVector(results);
    return 0;
}
