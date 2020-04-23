//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one
duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
 */
class Solution {
public:
    //  Floyd's Tortoise and Hare (Cycle Detection)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int target = nums[0];
        while (target != slow) {
            slow = nums[slow];
            target = nums[target];
        }
        return target;
    }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << Solution().findDuplicate(nums) << endl;
    return 0;
}