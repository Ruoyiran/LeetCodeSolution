//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int smallest = nums[0];
        int middle = INT32_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > middle) {
                return true;
            }
            if (nums[i] <= smallest) {
                smallest = nums[i];
            } else {
                middle = nums[i];
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {3,1,6,4,9};
    std::cout << Solution().increasingTriplet(nums) << std::endl;
    nums = {5,4,8,2,1};
    std::cout << Solution().increasingTriplet(nums) << std::endl;
    nums = {1,1,-2,6};
    std::cout << Solution().increasingTriplet(nums) << std::endl;
    nums = {1,0,0,10,0,0,0,0,100000000};
    std::cout << Solution().increasingTriplet(nums) << std::endl;
    return 0;
}