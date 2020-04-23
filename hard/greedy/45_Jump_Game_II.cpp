//
// Created by ranpeng on 2020/4/19.
//
#include "common.h"

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
class Solution {
public:
    int jump(vector<int> &nums) {
        int maxPos = 0, end = 0, nJumps = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            maxPos = std::max(maxPos, i+nums[i]);
            if (i == end) {
                ++nJumps;
                end = maxPos;
            }
        }
        return nJumps;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;
    return 0;
}