//
// Created by ranpeng on 2020/4/28.
//
#include "common.h"

/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution {
public:
    bool containsDuplicateV1(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n : nums) {
            if (s.find(n) != s.end()) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {1,2,3,1};
    std::cout << Solution().containsDuplicate(nums) << std::endl;
    return 0;
}