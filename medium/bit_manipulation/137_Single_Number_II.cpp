//
// Created by 冉鹏 on 2020/5/6.
//
#include "common.h"

/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int one = 0, two = 0;
        for (int i = 0; i < nums.size(); ++i) {
            one = one ^ nums[i] & (~two);
            two = two ^ nums[i] & (~one);
        }
        return one;
    }
};

int main() {
    vector<int> nums = {2,2,2,5};
    std::cout << Solution().singleNumber(nums) << std::endl;
    return 0;
}