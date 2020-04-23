//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [
5,7,7,8,8,10]
, target = 8
Output: [3,4]
Example 2:

Input: nums = [
5,7,7,8,8,10]
, target = 6
Output: [-1,-1]
 */
class Solution {
public:
    int searchLeft(vector<int> &nums, int end, int target) {
        int left = 0, right = end;
        int pos = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
                pos = mid;
            } else {
                left = mid + 1;
            }
        }
        return pos;
    }

    int searchRight(vector<int> &nums, int start, int target) {
        int left = start, right = nums.size()-1;
        int pos = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
                pos = mid;
            } else {
                right = mid - 1;
            }
        }
        return pos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        vector<int> indexes = {-1, -1};
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                int first = searchLeft(nums, mid-1, target);
                int last = searchRight(nums, mid+1, target);
                indexes[0] = first == -1 ? mid : first;
                indexes[1] = last == -1 ? mid : last;
                return indexes;
            }
            if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return indexes;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    Solution solution;
    auto result = solution.searchRange(nums, target);
    printVector(result);
}