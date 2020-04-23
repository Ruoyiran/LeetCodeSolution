//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            dist = std::max(dist, i + nums[i]);
            if (dist == i) {
                return false;
            }
            if (dist >= nums.size()-1) {
                return true;
            }
        }
        return dist >= nums.size()-1;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << boolalpha << Solution().canJump(nums) << endl;
    return 0;
}