//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/
class Solution {
private:
    void swap(vector<int>& nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

public:
    int missingNumberV1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i){
            while(nums[i] < nums.size() && i != nums[i])
                swap(nums, i, nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i)
                return i;
        return nums.size();
    }

    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            missing = (missing ^ i ^ nums[i]);
        }
        return missing;
    }
};

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}

