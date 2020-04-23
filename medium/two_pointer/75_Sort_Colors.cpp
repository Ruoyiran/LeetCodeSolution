//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
 */
class Solution {
public:
    // two-pass
    void sortColorsV1(vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        for(int n : nums) {
            if (n == 0) {
                ++zeroCount;
            } else if (n == 1) {
                ++oneCount;
            } else if (n == 2) {
                ++twoCount;
            }
        }
        for (int i = 0; i < zeroCount+oneCount+twoCount; ++i) {
            if (i < zeroCount) {
                nums[i] = 0;
            } else if (i < zeroCount + oneCount) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
    }

    // one-pass
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size()-1;
        while (one <= two) {
            if (nums[one] == 0) {
                swap(nums, one++, zero++);
            } else if (nums[one] == 2) {
                swap(nums, one, two--);
            } else {
                ++one;
            }
        }
    }
};

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    Solution().sortColors(nums);
    printVector(nums);
    return 0;
}