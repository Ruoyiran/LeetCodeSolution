//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

class Solution {
public:
    // Given an array nums, write a function to move all 0's to the end
    // of it while maintaining the relative order of the non-zero elements.
    void moveZeroesV1(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == 0) {
                int j = i+1;
                while (j < nums.size()-1 && nums[j] == 0) {
                    ++j;
                }
                swap(nums, i, j);
            }
        }
    }

    void moveZeroesV2(vector<int>& nums) {
        int lastNoneZeroPos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNoneZeroPos++] = nums[i];
            }
        }
        for (int i = lastNoneZeroPos; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }

    void moveZeroes(vector<int>& nums) {
        int lastNoneZeroPos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums, lastNoneZeroPos++, i);
            }
        }
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution solution;
    printVector(nums);
    solution.moveZeroes(nums);
    printVector(nums);
    return 0;
}